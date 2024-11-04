#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glvideowidget.h"
#include "FPGAInterface.h"

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
    // dock widget
    leftDk = ui-> leftDock;
    rightDk = ui -> rightDock;
    // widget
    videoWdt = ui->videoWidget;


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

    //open the YUV file
    //176x144
    // QFile f(":/akiyo_qcif.yuv");
    // f.open(QIODevice::ReadOnly);
    // QByteArray data(f.readAll());
    // qDebug("data size: %lld", data.size());
    FPGAInterface fpgaInterface;
    // QByteArray data;
    // Assuming you know the width and height of the image
    int width = 176;  // Example width
    int height = 144; // Example height
    std::vector<std::string> inputFiles = {
        ":/checkerboard_176x144-0.bin",
        ":/checkerboard_176x144-1.bin",
        ":/checkerboard_176x144-2.bin",
        ":/checkerboard_176x144-3.bin",
        ":/checkerboard_176x144-4.bin",
        ":/checkerboard_176x144-5.bin",
        ":/checkerboard_176x144-6.bin",
        ":/checkerboard_176x144-7.bin",
        ":/checkerboard_176x144-8.bin"
    };
    // fpgaInterface.convertGrayscaleToYUV(":/checkerboard_176x144-0.bin", data, width, height);
    QByteArray data = fpgaInterface.convertMultipleGrayscaleBinsToYUV(inputFiles, width, height);
    gl-> nextFrame(data);
}

// Play or pause video, reset UI
void MainWindow::pauseVideo(){
    if(gl->pauseVideo()){
        playPauseBtn->setIcon(QIcon(":/icons/pause.png"));
        recordBtn->setEnabled(false);
    }
    else{
        playPauseBtn->setIcon(QIcon(":/icons/play.png"));
        recordBtn->setEnabled(true);
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
