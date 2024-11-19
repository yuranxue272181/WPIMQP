#ifndef WIDGET_H
#define WIDGET_H

#include <QtOpenGL>
#include <QtGui/QImage>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>

class GLVideoWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLVideoWidget(QWidget *parent = 0);
    // YUV420P
    /*!
     * \brief setYUV420pParameters
     * call once before setFrameData() if parameters changed
     * \param w frame width
     * \param h frame height
     * \param strides strides of each plane. If null, it's equals to {w, w/2, w/2}.
     */
    void setYUV420pParameters(int w, int h, int* strides = NULL);

    void nextFrame(const QByteArray &data);

    // QImage
    /*!
     * \brief setQImageParameters
     * call once before setImage() if parameters changed
     * \param fmt only RGB888 is supported
     * \param stride QImage.bytesPerLine()
     */
    void setQImageParameters(QImage::Format fmt, int w, int h, int stride);
    void setImage(const QImage& img);
    bool pauseVideo();
    void saveYUVImageDataToFile();
    void saveYUVVideoDataToFile();
    void writeYUVVideoDataToFile();
    void startRecording();
    void stopRecording();
    bool toggleRecording();
    void refreshData();
    bool isPausedVideo();
    void setTrackingEnabled(bool enabled);
    void imageCoordinates();
    void processSelection();
    void setZoomFactor(float zoomFactor);


    // TODO: only init(w,h,strides) init(QImage::Format, w, h, strides)
protected:
    void bind();
    void bindPlane(int p);
    void initializeShader();
    void initTextures();
    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int w, int h) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    //basic effects
    GLint u_brightness;
    GLint u_contrast;
    GLint u_sharpness;
    GLint u_noiseReduction;
    GLint u_gamma;
    float currentBrightnessValue;
    float currentContrastValue;
    float currentSharpnessValue;
    float currentHEValue;
    float currentNRValue;
    float currentGammaValue;
    bool isPaused = false;
    bool isRecording = false;
    bool update_res;
    bool upload_tex;
    int videoWidth;
    int videoHeight;
    //char *pitch[3];
    QByteArray m_data;
    QImage m_image;
    QTimer *frameTimer;
    int currentFrameIndex = 0;
    QByteArray videoData;
    QByteArray frameData;
    QByteArray recordingData;
    QString filePath;
    int frameCount;
    QPoint selectionStart;
    QPoint selectionEnd;
    QPoint adjustedStart;
    QPoint adjustedEnd;
    bool selecting;
    bool trackingEnabled;
    float zoomFactor;

    typedef struct {
        char* data;
        int stride;
        GLint internal_fmt;
        GLenum fmt;
        GLenum type;
        int bpp;
        QSize tex_size;
        QSize upload_size;
    } Plane;
    QVector<Plane> plane;

    //QSize tex_size[3], tex_upload_size[3];
    GLuint tex[3];
    int u_MVP_matrix, u_colorMatrix, u_Texture[3];
    QOpenGLShaderProgram *m_program;
    QMutex m_mutex;
    QMatrix4x4 m_mat;

    void processNextFrame();
    void setFrameData(const QByteArray& data);
    void computeHistogramEqualization(char* yuvData);
    QPoint mapToImageCoordinates(const QPoint &point);


signals:
    void videoFinished();
    void selectionCompleted(const QPointF &start, const QPointF &end);
    void updateGrayValues(QVector<int> &grayValues);

public slots:
    void setBrightness(float value);
    void setContrast(float value);
    void setSharpness(float value);
    void setHEValue(float value);
    void setNoiseReduction(float value);
    void setGamma(float value);

private slots:
    void onTimerTimeout();
    void saveRecordingData();


};

#endif // WIDGET_H
