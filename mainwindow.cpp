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
    playBtn = ui->playButton;
    leftDk = ui-> leftDock;
    rightDk = ui -> rightDock;




    //opengl
    gl = new GLVideoWidget(this);

    //Connect the signal to the slot
    connect(playBtn, &QToolButton::clicked, this, &MainWindow::renderVideo);

    QApplication::setAttribute(Qt::AA_UseOpenGLES);
    gl-> setYUV420pParameters(176, 144); //call once

    //show the first frame
    // QFile f(":/akiyo_qcif.yuv");
    // f.open(QIODevice::ReadOnly);
    // QByteArray data(f.readAll());
    // qDebug("data size: %lld", data.size());
    // gl->setFrameData(data);


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


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::renderVideo(){
    //176x144
    QFile f(":/akiyo_qcif.yuv");
    f.open(QIODevice::ReadOnly);
    QByteArray data(f.readAll());
    qDebug("data size: %lld", data.size());
    gl->setFrameData(data);
    gl-> nextFrame(data);

}

