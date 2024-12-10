#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glvideowidget.h"
#include "fpgainterface.h"

//ui
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ui connection
    // button
    startBtn = ui->startButton;
    playPauseBtn = ui->playPauseButton;
    shootBtn = ui->shootButton;
    recordBtn = ui->recordButton;
    zoomInBtn = ui->zoomInButton;
    zoomOutBtn = ui->zoomOutButton;
    resetBtn = ui-> resetButton;
    // dock widget
    leftDk = ui-> leftDock;
    rightDk = ui -> rightDock;
    // widget
    videoWdt = ui->videoWidget;
    //slider
    brightnessSlider = ui->BrightnessSlider;
    contrastSlider = ui-> ContrastSlider;
    sharpnessSlider = ui-> SharpnessSlider;
    HESlider = ui->HESlider;
    NRSlider = ui->NRSlider;
    GammaSlider = ui -> GammaSlider;
    exposureTimeSlider = ui->exposureTimeSlider;
    gainSlider = ui-> gainSlider;
    dynamicRangeSlider = ui-> dynamicRangeSlider;
    STNRSlider = ui-> STNRSlider;

    //label
    brightnessValue = ui->brightness;
    contrastValue = ui-> contrast;
    sharpnessValue = ui-> sharpness;
    HEValue = ui->HE;
    NRValue = ui->NR;
    GammaValue = ui ->Gamma;
    GammaValue->setText("1");
    exposureTimeValue = ui-> exposureTime;
    gainValue = ui-> gain;
    dynamicRangeValue = ui-> dynamicRange;
    dynamicRangeValue->setText("60");
    STNRValue = ui-> STNR;
    STNRValue->setText("40");

    //table
    featuresTable = ui->FeatureTable;


    //initialize slider
    brightnessSlider ->setRange(-100, 100);
    brightnessSlider ->setValue(0);
    contrastSlider ->setRange(-100, 100);
    contrastSlider ->setValue(0);
    sharpnessSlider ->setRange(0,100);
    sharpnessSlider ->setValue(0);
    HESlider -> setRange(0,100);
    HESlider -> setValue(0);
    HESlider -> setEnabled(false);
    NRSlider ->setRange(0, 100);
    NRSlider ->setValue(0);
    GammaSlider -> setRange(1,30);
    GammaSlider -> setValue(10);
    exposureTimeSlider -> setRange(0,100);
    exposureTimeSlider -> setValue(0);
    gainSlider -> setRange(0,30);
    gainSlider -> setValue(0);
    dynamicRangeSlider -> setRange(60,120);
    dynamicRangeSlider -> setValue(60);
    STNRSlider -> setRange(30,70);
    STNRSlider -> setValue(40);


    // set icons
    startBtn->setIcon(QIcon(":/icons/restart.png"));
    startBtn->setIconSize(QSize(30,30));
    playPauseBtn->setIcon(QIcon(":/icons/pause.png"));
    playPauseBtn->setIconSize(QSize(30,30));
    playPauseBtn->setEnabled(false);
    shootBtn->setIcon(QIcon(":/icons/shoot.png"));
    shootBtn->setIconSize(QSize(30,30));
    shootBtn->setEnabled(false);
    recordBtn->setIcon(QIcon(":/icons/recordGray.png"));
    recordBtn->setIconSize(QSize(30,30));
    recordBtn->setEnabled(false);
    zoomInBtn->setIcon(QIcon(":/icons/zoomIn.png"));
    zoomInBtn->setIconSize(QSize(30,30));
    zoomOutBtn->setIcon(QIcon(":/icons/zoomOut.png"));
    zoomOutBtn->setIconSize(QSize(30,30));

    // openGL
    gl = new GLVideoWidget(this);
    QApplication::setAttribute(Qt::AA_UseOpenGLES);
    gl-> setYUV420pParameters(176, 144); //call once, frame size

    // Connect the signal to the slot
    connect(startBtn, &QToolButton::clicked, this, &MainWindow::renderVideo);
    connect(playPauseBtn, &QToolButton::clicked, this, &MainWindow::pauseVideo);
    connect(gl, &GLVideoWidget::videoFinished, this, &MainWindow::onVideoFinished);
    connect(zoomInBtn,&QToolButton::clicked, this, &MainWindow::zoomIn);
    connect(zoomOutBtn,&QToolButton::clicked, this, &MainWindow::zoomOut);
    connect(shootBtn, &QToolButton::clicked, gl, &GLVideoWidget::saveYUVImageDataToFile);
    connect(recordBtn,&QToolButton::clicked, this, &MainWindow::recordingStatu);
    connect(resetBtn, &QPushButton::clicked,this,&MainWindow::reset);
    connect(brightnessSlider, &QSlider::sliderMoved, this, &MainWindow::setBrightness);
    connect(contrastSlider, &QSlider::sliderMoved, this, &MainWindow::setContrast);
    connect(sharpnessSlider, &QSlider::sliderMoved, this, &MainWindow::setSharpness);
    connect(HESlider, &QSlider::sliderMoved, this, &MainWindow::setHEValue);
    connect(NRSlider, &QSlider::sliderMoved, this, &MainWindow::setNRValue);
    connect(GammaSlider, &QSlider::sliderMoved, this, &MainWindow::setGammaValue);
    connect(exposureTimeSlider, &QSlider::sliderMoved, this, &MainWindow::setExposureTimeValue);
    connect(gainSlider, &QSlider::sliderMoved, this, &MainWindow::setGainValue);
    connect(dynamicRangeSlider, &QSlider::sliderMoved, this, &MainWindow::setDynamicRangeValue);
    connect(STNRSlider, &QSlider::sliderMoved, this, &MainWindow::setSTNRValue);

    // connect the video to ui
    // clear the old layout of videoWidget
    if (ui->videoWidget->layout()) {
        QLayoutItem *item;
        while ((item = ui->videoWidget->layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    }
    // add GLVideoWidget to videoWidget
    QVBoxLayout *layout = new QVBoxLayout(ui->videoWidget);
    layout->addWidget(gl);
    ui->videoWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Render the video by OpenGL, display on the videoWidget, and reset UI
void MainWindow::renderVideo(){
    //button
    playPauseBtn->setEnabled(true);
    playPauseBtn->setIcon(QIcon(":/icons/play.png"));
    startBtn->setEnabled(false);
    shootBtn->setEnabled(true);
    recordBtn->setEnabled(true);
    HESlider -> setEnabled(true);

    //open the YUV file
    //176x144

    // int width=176;
    // int height = 144;
    // QFile f(":/akiyo_qcif.yuv");
    // f.open(QIODevice::ReadOnly);
    // //QByteArray data(f.readAll());
    // FPGAInterface fpgaInterface;
    // std::vector<std::string> inputFiles = {
    //     ":/checkerboard_176x144-0.bin",
    //     ":/checkerboard_176x144-1.bin",
    //     ":/checkerboard_176x144-2.bin",
    //     ":/checkerboard_176x144-3.bin",
    //     ":/checkerboard_176x144-4.bin",
    //     ":/checkerboard_176x144-5.bin",
    //     ":/checkerboard_176x144-6.bin",
    //     ":/checkerboard_176x144-7.bin",
    //     ":/checkerboard_176x144-8.bin"
    // };
    // QByteArray data = fpgaInterface.convertMultipleGrayscaleBinsToYUV(inputFiles, width, height);
    // //trans the video to only white, black ,and grey
    // int frameSize = (width * height) + (width / 2 * height / 2) * 2;
    // int frameCount = data.size() / frameSize;
    // for (int frame = 0; frame < frameCount; ++frame) {
    //     int frameOffset = frame * (width * height + (width / 2) * (height / 2) * 2);
    //     for (int j = 0; j < (width / 2) * (height / 2); ++j) {
    //         data[frameOffset + width * height + j] = -128; // U
    //         data[frameOffset + width * height + (width / 2) * (height / 2) + j] = -128; // V
    //     }
    // }
    // qDebug("data size: %lld", data.size());
    // gl->nextFrame(data);

    // int width=176;
    // int height = 144;
    // QFile f(":/akiyo_qcif.yuv");
    // f.open(QIODevice::ReadOnly);
    // QByteArray data(f.readAll());
    // //trans the video to only white, black ,and grey
    // int frameSize = (width * height) + (width / 2 * height / 2) * 2;
    // int frameCount = data.size() / frameSize;
    // for (int frame = 0; frame < frameCount; ++frame) {
    //     int frameOffset = frame * (width * height + (width / 2) * (height / 2) * 2);
    //     for (int j = 0; j < (width / 2) * (height / 2); ++j) {
    //         data[frameOffset + width * height + j] = -128; // U
    //         data[frameOffset + width * height + (width / 2) * (height / 2) + j] = -128; // V
    //     }
    // }
    // qDebug("data size: %lld", data.size());
    // gl->nextFrame(data);

    int width = 176;
    int height = 144;

    gl->connectFPGADevice(&fpga);
    gl->readVideoFromUSB();

}

// Play or pause video, reset UI
void MainWindow::pauseVideo(){
    if(gl->pauseVideo()){
        playPauseBtn->setIcon(QIcon(":/icons/pause.png"));
        recordBtn->setEnabled(false);
        //HESlider -> setEnabled(false);
    }
    else{
        playPauseBtn->setIcon(QIcon(":/icons/play.png"));
        recordBtn->setEnabled(true);
        HESlider -> setEnabled(true);
    }
}

// when the video finishes, reset the UI and stop recording
void MainWindow::onVideoFinished(){
    playPauseBtn->setIcon(QIcon(":/icons/pause.png"));
    playPauseBtn->setEnabled(false);
    startBtn->setEnabled(true);
    recordBtn->setEnabled(false);
    gl->stopRecording();
    recordBtn->setIcon(QIcon(":/icons/recordGray.png"));
    HESlider -> setEnabled(false);
}

// Zoom in the video
void MainWindow::zoomIn(){
    videoWdt->resize(videoWdt->width() * 1.1, videoWdt->height() * 1.1);
}

// Zoom in the video
void MainWindow::zoomOut(){
    videoWdt->resize(videoWdt->width() * 0.9, videoWdt->height() * 0.9);
}

// Start recording or stop recording, reset the UI
void MainWindow::recordingStatu(){
    if(gl->toggleRecording()){
        recordBtn->setIcon(QIcon(":/icons/recordRed.png"));
    }else{
        recordBtn->setIcon(QIcon(":/icons/recordGray.png"));
    }
}
void MainWindow::setBrightness(int brightness){
    brightnessValue->setText(QString::number(brightness));
    QTableWidgetItem *item = featuresTable->item(0,1);
    item->setText(QString::number(brightness));
    gl->setBrightness(brightness / 100.0f);
}

void MainWindow::setContrast(int contrast){
    contrastValue->setText(QString::number(contrast));
    QTableWidgetItem *item = featuresTable->item(1,1);
    item->setText(QString::number(contrast));
    gl->setContrast(contrast / 100.0f);
}
void MainWindow::setSharpness(int sharpness){
    sharpnessValue->setText(QString::number(sharpness));
    QTableWidgetItem *item = featuresTable->item(2,1);
    item->setText(QString::number(sharpness));
    gl->setSharpness(sharpness / 100.0f);
}

//set histogram equalization
void MainWindow::setHEValue(int value){
    HEValue -> setText(QString::number(value));
    QTableWidgetItem *item = featuresTable->item(3,1);
    item->setText(QString::number(value));
    gl -> setHEValue(value/ 100.0f);
    if(gl->isPausedVideo())
        gl -> refreshData();
}

//set noise reduction
void MainWindow::setNRValue(int value){
    NRValue -> setText(QString::number(value));
    QTableWidgetItem *item = featuresTable->item(4,1);
    item->setText(QString::number(value));
    gl -> setNoiseReduction(value/ 100.0f);
}

//set Gamma
void MainWindow::setGammaValue(int value){
    GammaValue -> setText(QString::number(value/10.0f));
    QTableWidgetItem *item = featuresTable->item(5,1);
    item->setText(QString::number(value/10.0f));
    gl -> setGamma(value/ 10.0f);
}

//reset to all image enhancement features to default
void MainWindow::reset(){
    // Reset sliders to their default values
    brightnessSlider->setValue(0);  // Brightness default
    contrastSlider->setValue(0);    // Contrast default
    sharpnessSlider->setValue(0);   // Sharpness default
    HESlider->setValue(0);          // Histogram Equalization default
    NRSlider->setValue(0);          // Noise Reduction default
    GammaSlider->setValue(10);      // Gamma default

    // Update the labels to reflect the new values
    brightnessValue->setText("0");
    contrastValue->setText("0");
    sharpnessValue->setText("0");
    HEValue->setText("0");
    NRValue->setText("0");
    GammaValue->setText("1"); // Gamma value is 1.0 when slider is at 10


    // Update the feature table to reflect the new values
    featuresTable->item(0, 1)->setText("0");
    featuresTable->item(1, 1)->setText("0");
    featuresTable->item(2, 1)->setText("0");
    featuresTable->item(3, 1)->setText("0");
    featuresTable->item(4, 1)->setText("0");
    featuresTable->item(5, 1)->setText("1.0"); // Gamma value is 1.0 when slider is at 10

    //update to openGL
    gl->setBrightness(0);
    gl->setSharpness(0);
    gl->setContrast(0);
    gl->setHEValue(0);
    gl->setNoiseReduction(0);
    gl->setGamma(1);
}

//hardware set exposure time
void MainWindow::setExposureTimeValue(int value){
    exposureTimeValue -> setText(QString::number(value));
    QTableWidgetItem *item = featuresTable->item(6,1);
    item->setText(QString::number(value));
    //在这里调用你的function
}
//hardware set gain
void MainWindow::setGainValue(int value){
    gainValue -> setText(QString::number(value));
    QTableWidgetItem *item = featuresTable->item(7,1);
    item->setText(QString::number(value));
    //在这里调用你的function
}
//hardware set dynamic range
void MainWindow::setDynamicRangeValue(int value){
    dynamicRangeValue -> setText(QString::number(value));
    QTableWidgetItem *item = featuresTable->item(8,1);
    item->setText(QString::number(value));
    //在这里调用你的function
}
//hardware set signal to noise ratio
void MainWindow::setSTNRValue(int value){
    STNRValue-> setText(QString::number(value));
    QTableWidgetItem *item = featuresTable->item(9,1);
    item->setText(QString::number(value));
    //在这里调用你的function
}

