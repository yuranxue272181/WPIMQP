#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glvideowidget.h"

//ui
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //dark model
    //mainWidget = ui->centralwidget;
    //mainWidget -> setStyleSheet("background-color: #353535;");

    //ui connection
    //button
    startBtn = ui->startButton;
    playPauseBtn = ui->playPauseButton;
    shootBtn = ui->shootButton;
    recordBtn = ui->recordButton;
    zoomInBtn = ui->zoomInButton;
    zoomOutBtn = ui->zoomOutButton;
    //dock widget
    leftDk = ui-> leftDock;
    rightDk = ui -> rightDock;


    //set icons
    startBtn->setIcon(QIcon(":/icons/restart.png"));
    startBtn->setIconSize(QSize(30,30));
    //startBtn->setEnabled(false); //waiting for loading opengl
    playPauseBtn->setIcon(QIcon(":/icons/pause.png"));
    playPauseBtn->setIconSize(QSize(30,30));
    playPauseBtn->setEnabled(false);
    shootBtn->setIcon(QIcon(":/icons/shoot.png"));
    shootBtn->setIconSize(QSize(30,30));
    recordBtn->setIcon(QIcon(":/icons/record.png"));
    recordBtn->setIconSize(QSize(30,30));
    zoomInBtn->setIcon(QIcon(":/icons/zoomIn.png"));
    zoomInBtn->setIconSize(QSize(30,30));
    zoomOutBtn->setIcon(QIcon(":/icons/zoomOut.png"));
    zoomOutBtn->setIconSize(QSize(30,30));


    //opengl
    gl = new GLVideoWidget(this);

    //Connect the signal to the slot
    connect(startBtn, &QToolButton::clicked, this, &MainWindow::renderVideo);
    connect(playPauseBtn, &QToolButton::clicked, this, &MainWindow::pauseVideo);
    connect(gl, &GLVideoWidget::videoFinished, this, &MainWindow::onVideoFinished);
    //connect(this,&MainWindow::glInitialized,this, &MainWindow::enableButton);

    QApplication::setAttribute(Qt::AA_UseOpenGLES);
    gl-> setYUV420pParameters(176, 144); //call once



    // clear the old layout
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
    //emit glInitialized();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::renderVideo(){
    //set playPauseBtn
    playPauseBtn->setEnabled(true);
    playPauseBtn->setIcon(QIcon(":/icons/play.png"));

    //176x144
    QFile f(":/akiyo_qcif.yuv");
    f.open(QIODevice::ReadOnly);
    QByteArray data(f.readAll());
    qDebug("data size: %lld", data.size());
    //gl->setFrameData(data);
    gl-> nextFrame(data);
}

void MainWindow::pauseVideo(){
    if(gl->pauseVideo()){
        playPauseBtn->setIcon(QIcon(":/icons/pause.png"));
    }
    else{
        playPauseBtn->setIcon(QIcon(":/icons/play.png"));
    }
}

void MainWindow::onVideoFinished(){
    playPauseBtn->setIcon(QIcon(":/icons/pause.png"));
    playPauseBtn->setEnabled(false);
}

void MainWindow::enableButton(){
    startBtn->setEnabled(true);
}

