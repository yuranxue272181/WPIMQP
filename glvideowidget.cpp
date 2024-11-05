#include "glvideowidget.h"
#include <QFile>
#include <QFileDialog>


//trans yuv to rgb
static const QMatrix4x4 yuv2rgb_bt601 =
    QMatrix4x4(
        1.0f,  0.000f,  1.402f, 0.0f,
        1.0f, -0.344f, -0.714f, 0.0f,
        1.0f,  1.772f,  0.000f, 0.0f,
        0.0f,  0.000f,  0.000f, 1.0f)
    *
    QMatrix4x4(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, -0.5f,
        0.0f, 0.0f, 1.0f, -0.5f,
        0.0f, 0.0f, 0.0f, 1.0f);

const GLfloat kVertices[] = {
    -1, 1,
    -1, -1,
    1, 1,
    1, -1,
};
const GLfloat kTexCoords[] = {
    0, 0,
    0, 1,
    1, 0,
    1, 1,
};

char const *const* attributes()
{
    static const char a0[] = {0x61, 0x5f, 0x50, 0x6f, 0x73, 0x0};
    static const char a1[] = {0x61, 0x5f, 0x54, 0x65, 0x78, 0x0};
    static const char a2[] = {0x00, 0x51, 0x74, 0x41, 0x56, 0x0};
    static const char* A[] = { a0, a1, a2};
    return A;
}

typedef struct {
    QImage::Format qfmt;
    GLint internal_fmt;
    GLenum fmt;
    GLenum type;
    int bpp;
} gl_fmt_entry_t;

#define glsl(x) #x
static const char kVertexShader[] = glsl(
    attribute vec4 a_Pos;
    attribute vec2 a_Tex;
    uniform mat4 u_MVP_matrix;
    varying vec2 v_TexCoords;
    void main() {
        gl_Position = u_MVP_matrix * a_Pos;
        v_TexCoords = a_Tex;
    });

static const char kFragmentShader[] = glsl(
    uniform sampler2D u_Texture0;
    uniform sampler2D u_Texture1;
    uniform sampler2D u_Texture2;
    varying mediump vec2 v_TexCoords;
    uniform mat4 u_colorMatrix;
    uniform float u_Brightness;
    uniform float u_Contrast;
    uniform float u_Sharpness;
    uniform float u_NoiseReduction;
    uniform float u_Gamma;
    void main()
    {
        vec2 texOffset = vec2(1.0 / 144.0, 1.0 / 176.0);
        vec4 color = u_colorMatrix
                             * vec4(
                                 texture2D(u_Texture0, v_TexCoords).r,
                                 texture2D(u_Texture1, v_TexCoords).r,
                                 texture2D(u_Texture2, v_TexCoords).r,
                                 1);

        // Noise Reduction: Gaussian filter
        if(u_NoiseReduction != 0.0){
            vec4 gaussianColor = vec4(0.0);
            float kernel[9];
            kernel[0] = 1.0; kernel[1] = 2.0; kernel[2] = 1.0;
            kernel[3] = 2.0; kernel[4] = 4.0; kernel[5] = 2.0;
            kernel[6] = 1.0; kernel[7] = 2.0; kernel[8] = 1.0;

            float kernelSum = 16.0;

            gaussianColor += texture2D(u_Texture0, v_TexCoords + vec2(-texOffset.x, -texOffset.y)) * kernel[0]; // top-left
            gaussianColor += texture2D(u_Texture0, v_TexCoords + vec2(0.0, -texOffset.y)) * kernel[1];          // top-center
            gaussianColor += texture2D(u_Texture0, v_TexCoords + vec2(texOffset.x, -texOffset.y)) * kernel[2];  // top-right
            gaussianColor += texture2D(u_Texture0, v_TexCoords + vec2(-texOffset.x, 0.0)) * kernel[3];          // center-left
            gaussianColor += texture2D(u_Texture0, v_TexCoords) * kernel[4];                                    // center
            gaussianColor += texture2D(u_Texture0, v_TexCoords + vec2(texOffset.x, 0.0)) * kernel[5];           // center-right
            gaussianColor += texture2D(u_Texture0, v_TexCoords + vec2(-texOffset.x, texOffset.y)) * kernel[6];  // bottom-left
            gaussianColor += texture2D(u_Texture0, v_TexCoords + vec2(0.0, texOffset.y)) * kernel[7];           // bottom-center
            gaussianColor += texture2D(u_Texture0, v_TexCoords + vec2(texOffset.x, texOffset.y)) * kernel[8];   // bottom-right

            gaussianColor /= kernelSum;
            color = mix(color, gaussianColor, u_NoiseReduction);
        }



        //sharpness

        if(u_Sharpness != 0.0){
            vec4 sharpColor = vec4(0.0);
            sharpColor += texture2D(u_Texture0, v_TexCoords + vec2(-texOffset.x, 0.0)) * (-1.0 * u_Sharpness); // left
            sharpColor += texture2D(u_Texture0, v_TexCoords + vec2(texOffset.x, 0.0)) * (-1.0 * u_Sharpness);  // right
            sharpColor += texture2D(u_Texture0, v_TexCoords + vec2(0.0, -texOffset.y)) * (-1.0 * u_Sharpness); // above
            sharpColor += texture2D(u_Texture0, v_TexCoords + vec2(0.0, texOffset.y)) * (-1.0 * u_Sharpness);  // below
            sharpColor += texture2D(u_Texture0, v_TexCoords) * (1.0 + 4.0 * u_Sharpness);                      // center
            color = mix(color, sharpColor, 0.5); // mix color
        }

        //brightness
        if(u_Brightness != 0.0)
            color.rgb += u_Brightness;
        //contrast
        if(u_Contrast != 0.0)
            color.rgb = ((color.rgb - 0.5) * (1.0 + u_Contrast)) + 0.5;

        // Gamma Correction 0.1-3.0
        if(u_Gamma != 0.0)
            color.rgb = pow(color.rgb, vec3(1.0 / u_Gamma));


        gl_FragColor = clamp(color, 0.0, 1.0);

    });
// not used
static const char kFragmentShaderRGB[] = glsl(
    uniform sampler2D u_Texture0;
    varying mediump vec2 v_TexCoords;
    void main() {
        vec4 c = texture2D(u_Texture0, v_TexCoords);
        gl_FragColor = c.rgba;
        // vec4 color = texture2D(u_Texture0, v_TexCoords);
        // color.rgb += u_brightness; // change brightness
        // gl_FragColor = clamp(color, 0.0, 1.0);
    });
#undef glsl

// Constructor
GLVideoWidget::GLVideoWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , update_res(true)
    , upload_tex(true)
    , m_program(0)
    , currentBrightnessValue(0.0f)
    , currentContrastValue(0.0f)
    , currentSharpnessValue(0.0f)
    , currentHEValue(0.0f)
    , currentNRValue(0.0f)
    , currentGammaValue(1.0f)
    ,frameCount(0)
{
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);
    //default: swap in qpainter dtor. we should swap before QPainter.endNativePainting()
    memset(tex, 0, 3 * sizeof(GLuint));

}

// render one frame
void GLVideoWidget::setFrameData(const QByteArray &data)
{
    QMutexLocker lock(&m_mutex);
    Q_UNUSED(lock);
    upload_tex = true;
    m_data = data;
    plane[0].data = (char*)m_data.constData();

    //debug
    //qDebug() << "Received frame data size:" << m_data.size();

    if (plane.size() > 1) {
        plane[1].data = plane[0].data + plane[0].stride*height;
        plane[2].data = plane[1].data + plane[1].stride*height/2;
    }
    update();
}


// display video by switching frames (frame rate)
void GLVideoWidget::nextFrame(const QByteArray &data) {
    videoData = data;
    currentFrameIndex = 0; // reset
    // set timer
    frameTimer = new QTimer(this);
    qDebug() << "Timer setted.";
    connect(frameTimer, &QTimer::timeout, this, &GLVideoWidget::processNextFrame);
    frameTimer->start(1000/30); // 30FPS
}

//Get the data for each frame and render it
void GLVideoWidget::processNextFrame() {
    const int frameSize = width * height * 3;
    if (currentFrameIndex * frameSize < videoData.size()) {
        frameData = videoData.mid(currentFrameIndex * frameSize, frameSize);
        setFrameData(frameData);
        currentFrameIndex++;
    } else {
        frameTimer->stop();
        delete frameTimer;
        frameTimer = nullptr;
        qDebug() << "All frames processed.";
        emit videoFinished();
    }
}

// start or stop recording
bool GLVideoWidget::toggleRecording() {
    if (isRecording) {
        stopRecording();
    } else {
        startRecording();
    }
    return isRecording;
}

void GLVideoWidget::saveRecordingData(){
    recordingData.append(frameData);
}

// start recording
void GLVideoWidget::startRecording(){
    isRecording = true;
    recordingData.clear();
    saveYUVVideoDataToFile();
    connect(frameTimer, &QTimer::timeout, this, &GLVideoWidget::saveRecordingData);
    connect(frameTimer, &QTimer::timeout, this, &GLVideoWidget::onTimerTimeout);

}

// stop recording and save the YUV file
void GLVideoWidget::stopRecording(){
    if(isRecording){
        isRecording = false;
        disconnect(frameTimer, &QTimer::timeout, this, &GLVideoWidget::saveRecordingData);
        disconnect(frameTimer, &QTimer::timeout, this, &GLVideoWidget::onTimerTimeout);
        writeYUVVideoDataToFile();
        qDebug() << "Recording stopped.";
    }
}
// write data to the file every second
void GLVideoWidget::onTimerTimeout(){
    frameCount++;
    if (frameCount >= 30) {
        writeYUVVideoDataToFile();
        frameCount = 0;
    }
}

// save the screenshoot
void GLVideoWidget::saveYUVImageDataToFile() {
    if (frameData.isEmpty()) {
        qDebug() << "No frame data to save.";
        return;
    }
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save YUV File of Image"),
                                                    QString(),
                                                    tr("YUV Files (*.yuv);;All Files (*)"));
    if (filePath.isEmpty()) {
        qDebug() << "No file selected.";
        return;
    }
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(frameData);
        file.close();
        qDebug() << "Frame" << currentFrameIndex << "saved to" << filePath;
        qDebug() << "Saved frame size:" << frameData.size()/width/height/3;
    } else {
        qDebug() << "Failed to save frame to" << filePath;
    }
}

// save the recording
void GLVideoWidget::saveYUVVideoDataToFile() {
    recordingData.clear();
    qDebug() << "Recording started.";
    filePath = QFileDialog::getSaveFileName(this, tr("Save YUV File of Video"),
                                                    QString(),
                                                    tr("YUV Files (*.yuv);;All Files (*)"));
    if (filePath.isEmpty()) {
        qDebug() << "No file selected.";
        return;
    }
}

void GLVideoWidget::writeYUVVideoDataToFile(){
    if (recordingData.isEmpty()) {
        qDebug() << "No frame data to save.";
        return;
    }
    QByteArray saveData = recordingData;
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly| QIODevice::Append)) {
        file.write(saveData);
        recordingData.remove(0,saveData.size());
        file.close();
        qDebug() <<"saved to" << filePath;
    } else {
        qDebug() << "Failed to save frame to" << filePath;
    }
}

// play or pause the video (frame rate)
bool GLVideoWidget::pauseVideo(){
    if (frameTimer) {
        if (isPaused) {
            //resume
            frameTimer->start(1000 / 30);
            isPaused = false;
            qDebug() << "Video resumed.";
        } else {
            // pasue
            frameTimer->stop();
            isPaused = true;
            qDebug() << "Video paused.";
        }
    }
    return isPaused;
}

// set image
void GLVideoWidget::setImage(const QImage &img)
{
    QMutexLocker lock(&m_mutex);
    Q_UNUSED(lock);
    upload_tex = true;
    m_image = img;
    plane[0].data = (char*)m_image.constBits();
    update();
}

//set brightness
void GLVideoWidget::setBrightness(float value){
    currentBrightnessValue = value;
    update();
}

//set contrast
void GLVideoWidget::setContrast(float value){
    currentContrastValue = value;
    update();
}

//set sharpness
void GLVideoWidget::setSharpness(float value){
    currentSharpnessValue = value;
    update();
}

//set noise reduction
void GLVideoWidget::setNoiseReduction(float value){
    currentNRValue = value;
    update();
}

//set histogram equalization strength
void GLVideoWidget::setHEValue(float value){
    currentHEValue = value;
    update();
}

//set Gamma Correction
void GLVideoWidget::setGamma(float value){
    currentGammaValue = value;
    update();
}

// Binds an OpenGL resource to the current OpenGL
void GLVideoWidget::bind()
{
    for (int i = 0; i < plane.size(); ++i) {
        bindPlane((i + 1) % plane.size());
    }
    upload_tex = false;
}

// Binds plane to the current OpenGL
void GLVideoWidget::bindPlane(int p)
{
    glActiveTexture(GL_TEXTURE0 + p);
    glBindTexture(GL_TEXTURE_2D, tex[p]);
    if (!upload_tex)
        return;
    // This is necessary for non-power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    const Plane &P = plane[p];
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, P.upload_size.width(), P.upload_size.height(), P.fmt, P.type, P.data);
}
// initialize textures
void GLVideoWidget::initTextures()
{
    glDeleteTextures(3, tex);
    memset(tex, 0, 3 * sizeof(GLuint));
    glGenTextures(plane.size(), tex);
    //qDebug("init textures...");
    for (int i = 0; i < plane.size(); ++i) {
        const Plane &P = plane[i];
        //qDebug("tex[%d]: %u", i, tex[i]);
        glBindTexture(GL_TEXTURE_2D, tex[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        // This is necessary for non-power-of-two textures
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, P.internal_fmt, P.tex_size.width(), P.tex_size.height(), 0/*border, ES not support*/, P.fmt, P.type, NULL);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

// Setting parameters for video frames in YUV420p format (frame size)
void GLVideoWidget::setYUV420pParameters(int w, int h, int *strides)
{
    QMutexLocker lock(&m_mutex);
    Q_UNUSED(lock);
    update_res = true;
    m_data.clear();
    m_image = QImage();
    width = w;
    height = h;
    plane.resize(3);
    Plane &p = plane[0];
    p.data = 0;
    p.stride = strides && strides[0] ? strides[0] : w;
    p.tex_size.setWidth(p.stride);
    p.upload_size.setWidth(p.stride);
    p.tex_size.setHeight(h);
    p.upload_size.setHeight(h);
    p.internal_fmt = p.fmt = GL_LUMINANCE;
    p.type = GL_UNSIGNED_BYTE;
    p.bpp = 1;
    for (int i = 1; i < plane.size(); ++i) {
        Plane &p = plane[i];
        p.stride = strides && strides[i] ? strides[i] : w/2;
        p.tex_size.setWidth(p.stride);
        p.upload_size.setWidth(p.stride);
        p.tex_size.setHeight(h/2);
        p.upload_size.setHeight(h/2);
        p.internal_fmt = p.fmt = GL_LUMINANCE;
        p.type = GL_UNSIGNED_BYTE;
        p.bpp = 1;
        qDebug() << p.tex_size;
    }
}

// set Qimage parameters
void GLVideoWidget::setQImageParameters(QImage::Format fmt, int w, int h, int stride)
{
    QMutexLocker lock(&m_mutex);
    Q_UNUSED(lock);
    update_res = true;
    m_data.clear();
    m_image = QImage();
    width = w;
    height = h;
    plane.resize(1);
    Plane &p = plane[0];
    p.data = 0;
    p.stride = stride ? stride : QImage(w, h, fmt).bytesPerLine();
    static const gl_fmt_entry_t fmts[] = {
        { QImage::Format_RGB888, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, 3},
        { QImage::Format_Invalid, 0, 0, 0, 0}
    };
    for (int i = 0; fmts[i].bpp; ++i) {
        if (fmts[i].qfmt == fmt) {
            Plane &p = plane[0];
            p.internal_fmt = fmts[i].internal_fmt;
            p.fmt = fmts[i].fmt;
            p.type = fmts[i].type;
            p.internal_fmt = fmts[i].internal_fmt;
            p.bpp = fmts[i].bpp;

            p.tex_size.setWidth(p.stride/p.bpp);
            p.upload_size.setWidth(p.stride/p.bpp);
            p.tex_size.setHeight(h);
            p.upload_size.setHeight(h);
            return;
        }
    }
    qFatal("Unsupported QImage format %d!", fmt);
}

// paint
void GLVideoWidget::paintGL()
{
    QMutexLocker lock(&m_mutex);
    Q_UNUSED(lock);
    if (!plane[0].data){
        qDebug() << "No frame data to render!";
        return;
    }

    //qDebug() << "Rendering frame with width:" << width << "height:" << height;


    //histogram equalization
    if (currentHEValue != 0.0)
    computeHistogramEqualization(plane[0].data);

    if (update_res || !tex[0]) {
        initializeShader();
        initTextures();
        update_res = false;

    }
    bind();
    m_program->bind();
    m_program->setUniformValue(u_brightness, currentBrightnessValue);
    m_program->setUniformValue(u_contrast, currentContrastValue);
    m_program->setUniformValue(u_sharpness, currentSharpnessValue);
    m_program->setUniformValue(u_noiseReduction,currentNRValue);
    m_program->setUniformValue(u_gamma, currentGammaValue);
    for (int i = 0; i < plane.size(); ++i) {
        m_program->setUniformValue(u_Texture[i], (GLint)i);
    }
    m_program->setUniformValue(u_colorMatrix, yuv2rgb_bt601);
    m_program->setUniformValue(u_MVP_matrix, m_mat);
    // uniform end. attribute begin
    // kVertices ...
    // normalize?
    m_program->setAttributeArray(0, GL_FLOAT, kVertices, 2);
    m_program->setAttributeArray(1, GL_FLOAT, kTexCoords, 2);
    char const *const *attr = attributes();
    for (int i = 0; attr[i][0]; ++i) {
        m_program->enableAttributeArray(i); //TODO: in setActiveShader
    }
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    for (int i = 0; attr[i][0]; ++i) {
        m_program->disableAttributeArray(i); //TODO: in setActiveShader
    }
    //update();
}

// initialize openGL
void GLVideoWidget::initializeGL()
{
    initializeOpenGLFunctions();
}

// resize openGL
void GLVideoWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    m_mat.setToIdentity();
    //m_mat.ortho(QRectF(0, 0, w, h));
}
// initialize shader
void GLVideoWidget::initializeShader()
{
    if (m_program) {
        m_program->release();
        delete m_program;
        m_program = 0;
    }
    m_program = new QOpenGLShaderProgram(this);

    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, kVertexShader);
    QByteArray frag;
    if (plane.size() > 1)
        frag = QByteArray(kFragmentShader);
    else
        frag = QByteArray(kFragmentShaderRGB);
    frag.prepend("#ifdef GL_ES\n"
                 "precision mediump int;\n"
                 "precision mediump float;\n"
                 "#else\n"
                 "#define highp\n"
                 "#define mediump\n"
                 "#define lowp\n"
                 "#endif\n");
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, frag);

    char const *const *attr = attributes();
    for (int i = 0; attr[i][0]; ++i) {
        m_program->bindAttributeLocation(attr[i], i);
    }
    if (!m_program->link()) {
        qWarning("QSGMaterialShader: Shader compilation failed:");
        qWarning() << m_program->log();
        qDebug("frag: %s", plane.size() > 1 ? kFragmentShader : kFragmentShaderRGB);
    }
    u_brightness = m_program->uniformLocation("u_Brightness");
    if (u_brightness == -1) {
        qDebug() << "Uniform 'u_Brightness' not found in shader.";
    }
    u_contrast = m_program->uniformLocation("u_Contrast");
    if (u_contrast == -1) {
        qDebug() << "Uniform 'u_Contrast' not found in shader.";
    }
    u_sharpness = m_program->uniformLocation("u_Sharpness");
    if (u_sharpness == -1) {
        qDebug() << "Uniform 'u_Sharpness' not found in shader.";
    }
    u_noiseReduction= m_program->uniformLocation("u_NoiseReduction");
    if (u_noiseReduction == -1) {
        qDebug() << "Uniform 'u_NoiseReduction' not found in shader.";
    }
    u_gamma = m_program->uniformLocation("u_Gamma");
    if (u_gamma == -1) {
        qDebug() << "Uniform 'u_Gamma' not found in shader.";
    }

    u_MVP_matrix = m_program->uniformLocation("u_MVP_matrix");
    // fragment shader
    u_colorMatrix = m_program->uniformLocation("u_colorMatrix");
    for (int i = 0; i < plane.size(); ++i) {
        QString tex_var = QString("u_Texture%1").arg(i);
        u_Texture[i] = m_program->uniformLocation(tex_var);
        qDebug("glGetUniformLocation(\"%s\") = %d", tex_var.toUtf8().constData(), u_Texture[i]);
    }
    qDebug("glGetUniformLocation(\"u_MVP_matrix\") = %d", u_MVP_matrix);
    qDebug("glGetUniformLocation(\"u_colorMatrix\") = %d", u_colorMatrix);

}

//Calculate the Y-component after histogram equalization
void GLVideoWidget::computeHistogramEqualization(char* data){
    const int L = 256; //gray scale
    int histogram[L] = {0};
    int totalPixels = 176 * 144;

    //calculate the histogram
    for (int i = 0; i < totalPixels; ++i) {
        uchar pixelValue = static_cast<uchar>(data[i]);
        histogram[pixelValue]++;
    }

    //calculate CDF
    int cdf[L] = {0};
    cdf[0] = histogram[0];
    for (int i = 1; i < L; ++i) {
        cdf[i] = cdf[i - 1] + histogram[i];
    }

    //generate the equalizationMap
    uchar equalizationMap[L];
    int cdfMin = cdf[0];
    for (int i = 0; i < L; ++i) {
        equalizationMap[i] = static_cast<uchar>(((cdf[i] - cdfMin) * (L - 1)) / (totalPixels - cdfMin));
    }

    //update the Y_component data
    for (int i = 0; i < totalPixels; ++i) {
        uchar originalPixelValue = static_cast<uchar>(data[i]);
        uchar equalizedPixelValue = equalizationMap[originalPixelValue];
        if (currentHEValue < 100) {
            data[i] = static_cast<uchar>(equalizedPixelValue * currentHEValue + originalPixelValue * (1.0f - currentHEValue));
        } else {
            data[i] = equalizedPixelValue;
        }
    }

}

