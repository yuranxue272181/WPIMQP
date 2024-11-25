#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glvideowidget.h"
#include "analysis.h"

//ui
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    zoomFactor = 1.0f;


    // ui connection
    // button
    startBtn = ui->startButton;
    playPauseBtn = ui->playPauseButton;
    shootBtn = ui->shootButton;
    recordBtn = ui->recordButton;
    zoomInBtn = ui->zoomInButton;
    zoomOutBtn = ui->zoomOutButton;
    resetBtn = ui-> resetButton;
    grabBtn = ui-> grabButton;
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
    coordTable = ui->coordinatesTable;
    analysisTable = ui->analysisTable;

    //initialize slider and button
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
    grabBtn -> setCheckable(true);
    grabBtn -> setEnabled(false);


    // initialize icons
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

    //analysis
    analysis = new Analysis();

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
    connect(grabBtn,&QPushButton::clicked,this,&MainWindow::setTrackingEnabled);
    connect(gl, &GLVideoWidget::selectionCompleted, this, &MainWindow::onSelectionCompleted);
    connect(gl, &GLVideoWidget::updateGrayValues, this, &MainWindow::updateAnalysis);

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
    delete gl;
    delete analysis;
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
    grabBtn -> setEnabled(true);

    //open the YUV file
    //176x144
    int width=176;
    int height = 144;
    QFile f(":/akiyo_qcif.yuv");
    f.open(QIODevice::ReadOnly);
    QByteArray data(f.readAll());
    //trans the video to only white, black ,and grey
    int frameSize = (width * height) + (width / 2 * height / 2) * 2;
    int frameCount = data.size() / frameSize;
    for (int frame = 0; frame < frameCount; ++frame) {
        int frameOffset = frame * (width * height + (width / 2) * (height / 2) * 2);
        for (int j = 0; j < (width / 2) * (height / 2); ++j) {
            data[frameOffset + width * height + j] = -128; // U
            data[frameOffset + width * height + (width / 2) * (height / 2) + j] = -128; // V
        }
    }
    qDebug("data size: %lld", data.size());
    gl->nextFrame(data);
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
    if(zoomFactor<qPow(1.05, 6))
    zoomFactor *= 1.05;
    videoWdt->resize(352*zoomFactor, 288*zoomFactor);
    if(grabBtn->isChecked()){
        gl->setZoomFactor(zoomFactor);
    }
}

// Zoom out the video
void MainWindow::zoomOut(){
    if(zoomFactor>1)
        zoomFactor *= 0.95;
    if(zoomFactor<1)
        zoomFactor =1;
    videoWdt->resize(352*zoomFactor, 288*zoomFactor);
    if(grabBtn->isChecked()){
        gl->setZoomFactor(zoomFactor);
    }
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

    gl -> refreshData();
}

//hardware set exposure time
void MainWindow::setExposureTimeValue(int value){
    exposureTimeValue -> setText(QString::number(value));
    QTableWidgetItem *item = featuresTable->item(6,1);
    item->setText(QString::number(value));

}
//hardware set gain
void MainWindow::setGainValue(int value){
    gainValue -> setText(QString::number(value));
    QTableWidgetItem *item = featuresTable->item(7,1);
    item->setText(QString::number(value));

}
//hardware set dynamic range
void MainWindow::setDynamicRangeValue(int value){
    dynamicRangeValue -> setText(QString::number(value));
    QTableWidgetItem *item = featuresTable->item(8,1);
    item->setText(QString::number(value));

}
//hardware set signal to noise ratio
void MainWindow::setSTNRValue(int value){
    STNRValue-> setText(QString::number(value));
    QTableWidgetItem *item = featuresTable->item(9,1);
    item->setText(QString::number(value));

}

void MainWindow::setTrackingEnabled(){
    gl -> setTrackingEnabled(grabBtn->isChecked());
}

void MainWindow::onSelectionCompleted(const QPointF &start, const QPointF &end) {
    QTableWidgetItem *x1 = coordTable->item(0,0);
    QTableWidgetItem *y1 = coordTable->item(0,1);
    x1->setText(QString::number(start.x()));
    y1->setText(QString::number(start.y()));
    QTableWidgetItem *x2 = coordTable->item(1,0);
    QTableWidgetItem *y2 = coordTable->item(1,1);
    x2->setText(QString::number(end.x()));
    y2->setText(QString::number(start.y()));
    QTableWidgetItem *x3 = coordTable->item(2,0);
    QTableWidgetItem *y3 = coordTable->item(2,1);
    x3->setText(QString::number(start.x()));
    y3->setText(QString::number(end.y()));
    QTableWidgetItem *x4 = coordTable->item(3,0);
    QTableWidgetItem *y4 = coordTable->item(3,1);
    x4->setText(QString::number(end.x()));
    y4->setText(QString::number(end.y()));
}

//update data analysis to the table
void MainWindow::updateAnalysis(std::shared_ptr<QVector<int>> grayValues, int selectedWidth, int selectedHeight){
    if (!grayValues || grayValues->isEmpty()) {
        qWarning() << "Received null or empty grayValues!";
        return;
    }
    float mean = analysis->meanCal(grayValues);
    QTableWidgetItem *meanItem = analysisTable->item(2, 1);
    meanItem->setText(QString::number(mean));

    float minValue = *std::min_element(grayValues->begin(), grayValues->end());
    float maxValue = *std::max_element(grayValues->begin(), grayValues->end());
    QTableWidgetItem *minItem = analysisTable->item(0, 1);
    minItem->setText(QString::number(minValue));
    QTableWidgetItem *maxItem = analysisTable->item(1, 1);
    maxItem->setText(QString::number(maxValue));

    float pixelNoise = analysis->pixelNoiseCal(grayValues, mean);
    QTableWidgetItem *stdDevItem = analysisTable->item(3, 1);
    stdDevItem->setText(QString::number(pixelNoise));

    float rowNoise = analysis->calculateAllRowNoise(grayValues, selectedHeight, selectedWidth);
    QTableWidgetItem *rowItem = analysisTable->item(4, 1);
    rowItem->setText(QString::number(rowNoise));

    float columnNoise = analysis->calculateAllColumnNoise(grayValues, selectedHeight, selectedWidth);
    QTableWidgetItem *columnItem = analysisTable->item(5, 1);
    columnItem->setText(QString::number(columnNoise));
    // //mean
    // float mean = meanCal(grayValues);
    // QTableWidgetItem *meanItem = analysisTable -> item(2,1);
    // meanItem->setText(QString::number(mean));

    // //min & max
    // float minValue = *std::min_element(grayValues->begin(), grayValues->end());
    // float maxValue = *std::max_element(grayValues->begin(), grayValues->end());
    // QTableWidgetItem *minItem = analysisTable -> item(0,1);
    // minItem->setText(QString::number(minValue));
    // QTableWidgetItem *maxItem = analysisTable -> item(1,1);
    // maxItem->setText(QString::number(maxValue));

    // //pixel Noise (standard deviation)
    // float pixelNoise = pixelNoiseCal(grayValues,mean);
    // QTableWidgetItem *stdDevItem = analysisTable->item(3, 1);
    // stdDevItem->setText(QString::number(pixelNoise));

    // //row noise
    // float rowNoise = calculateAllRowNoise(grayValues, selectedHeight, selectedWidth);
    // //qDebug()<<"row noise"<<rowNoise;
    // QTableWidgetItem *rowItem = analysisTable->item(4, 1);
    // rowItem->setText(QString::number(rowNoise));

    // //column noise
    // float columnNoise = calculateAllColumnNoise(grayValues, selectedHeight, selectedWidth);
    // //qDebug()<<"column noise"<<columnNoise;
    // QTableWidgetItem *columnItem = analysisTable->item(5, 1);
    // columnItem->setText(QString::number(columnNoise));
}
// //calculate mean of ROI
// float MainWindow::meanCal(std::shared_ptr<QVector<int>> grayValues){
//     //mean
//     float mean = 0.0f;
//     for (int value : *grayValues) {
//         mean += value;
//     }
//     mean /= grayValues->size();
//     return mean;
// }

// //calculate standard deviation of ROI
// float MainWindow::pixelNoiseCal(std::shared_ptr<QVector<int>> grayValues, float mean){
//     float variance = 0.0f;
//     for (int value : *grayValues) {
//         variance += std::pow(value - mean, 2);
//     }
//     variance /= grayValues->size();
//     return std::sqrt(variance);
// }

// //calculate row noise for one row
// float MainWindow::calculateRowNoise(std::shared_ptr<QVector<int>> grayValues, int rowIndex, int selectedWidth) {
//     float mean = 0.0f;
//     int rowStartIndex = rowIndex * selectedWidth;
//     int rowEndIndex = rowStartIndex + selectedWidth;

//     for (int i = rowStartIndex; i < rowEndIndex; ++i) {
//         mean += (*grayValues)[i];
//     }
//     mean /= selectedWidth;

//     float variance = 0.0f;
//     for (int i = rowStartIndex; i < rowEndIndex; ++i) {
//         variance += std::pow((*grayValues)[i] - mean, 2);
//     }
//     variance /= selectedWidth;
//     return std::sqrt(variance);
// }

// //calculate all row noise
// float MainWindow::calculateAllRowNoise(std::shared_ptr<QVector<int>> grayValues, int selectedHeight, int selectedWidth) {
//     if(selectedHeight == 1)
//         return 0;
//     QVector<float> rowNoiseValues;
//     float mean = 0.0f;
//     for (int row = 0; row < selectedHeight; ++row) {
//         float rowNoise = calculateRowNoise(grayValues, row, selectedWidth);
//         rowNoiseValues.append(rowNoise);
//         mean+=rowNoise;
//     }
//     mean /= rowNoiseValues.size();
//     float rowNoiseVariance = 0.0f;
//     for (float noise : rowNoiseValues) {
//         rowNoiseVariance += std::pow(noise - mean, 2);
//     }
//     rowNoiseVariance /= rowNoiseValues.size();
//     return std::sqrt(rowNoiseVariance);
// }
// //calculate column noise of one column
// float MainWindow::calculateColumnNoise(std::shared_ptr<QVector<int>> grayValues, int columnIndex, int selectedHeight, int selectedWidth){
//     float mean = 0.0f;
//     for (int row = 0; row < selectedHeight; ++row) {
//         mean += (*grayValues)[row * selectedWidth + columnIndex];
//     }
//     mean /= selectedHeight;
//     float variance = 0.0f;
//     for (int row = 0; row < selectedHeight; ++row) {
//         variance += std::pow((*grayValues)[row * selectedWidth + columnIndex] - mean, 2);
//     }
//     variance /= selectedHeight;
//     return std::sqrt(variance);
// }

// //calculate all column noise
// float MainWindow::calculateAllColumnNoise(std::shared_ptr<QVector<int>> grayValues, int selectedHeight, int selectedWidth) {
//     if (selectedWidth == 1)
//         return 0;
//     QVector<float> columnNoiseValues;
//     float mean = 0.0f;
//     for (int col = 0; col < selectedWidth; ++col) {
//         float columnNoise = calculateColumnNoise(grayValues, col, selectedHeight, selectedWidth);
//         columnNoiseValues.append(columnNoise);
//         mean += columnNoise;
//     }
//     mean /= columnNoiseValues.size();
//     float columnNoiseVariance = 0.0f;
//     for (float noise : columnNoiseValues) {
//         columnNoiseVariance += std::pow(noise - mean, 2);
//     }

//     columnNoiseVariance /= columnNoiseValues.size();
//     return std::sqrt(columnNoiseVariance);
// }





