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

    //initialize
    zoomFactor = 1.0f;
    selectedH = 0;
    selectedW = 0;
    //selectedRegion = std::make_shared<QVector<int>>(1, 0);
    selectedRegion = nullptr;
    totalMin = 256;
    totalMax = -1;
    totalMeanSum = 0.0f;
    totalMeanCounter = 0;
    totalPixelSum = 0.0f;
    totalPixelCounter = 0;
    totalRowCounter = 0;
    totalRowSum = 0.0f;
    totalColumnCounter = 0;
    totalColumnSum = 0.0f;

    // ui
    // button
    startBtn = ui->startButton;
    playPauseBtn = ui->playPauseButton;
    shootBtn = ui->shootButton;
    recordBtn = ui->recordButton;
    zoomInBtn = ui->zoomInButton;
    zoomOutBtn = ui->zoomOutButton;
    resetBtn = ui-> resetButton;
    grabBtn = ui-> grabButton;
    //spinBox
    temporalFrame = new QSpinBox();
    temporalFrame->setMinimum(3);
    temporalFrame->setMaximum(50);
    temporalFrame->setValue(10);
    // widget
    videoWdt = ui->videoWidget;
    spinWdt = ui->spin;
    QVBoxLayout *layout1 = new QVBoxLayout(spinWdt);
    layout1->addWidget(temporalFrame);
    spinWdt->setLayout(layout1);

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

    //checkBox
    minChecker = new QCheckBox("Minimum");
    //minChecker->setStyleSheet("QCheckBox { margin-left: auto; margin-right: auto; }");
    maxChecker= new QCheckBox("Maximum");
    averageChecker= new QCheckBox("Average");
    rowChecker= new QCheckBox("Row Noise");
    columnChecker= new QCheckBox("Column Noise");
    pixelChecker= new QCheckBox("Pixel Noise");



    //table
    featuresTable = ui->FeatureTable;
    coordTable = ui->coordinatesTable;
    QStringList rowHeaders;
    rowHeaders << "x1" << "x2";
    coordTable->setVerticalHeaderLabels(rowHeaders);
    analysisTable = ui->analysisTable;
    analysisTable->setCellWidget(0, 0, minChecker);
    analysisTable->setCellWidget(1, 0, maxChecker);
    analysisTable->setCellWidget(2, 0, averageChecker);
    analysisTable->setCellWidget(3, 0, pixelChecker);
    analysisTable->setCellWidget(4, 0, rowChecker);
    analysisTable->setCellWidget(5, 0, columnChecker);
    analysisTable->setEnabled(false);
    analysisTable->setStyleSheet("QTableWidget { background-color: #f0f0f0; color: gray; }");

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
    connect(minChecker, &QCheckBox::stateChanged, this, &MainWindow::minCheck);
    connect(maxChecker, &QCheckBox::stateChanged, this, &MainWindow::maxCheck);
    connect(averageChecker, &QCheckBox::stateChanged, this, &MainWindow::avegCheck);
    connect(pixelChecker, &QCheckBox::stateChanged, this, &MainWindow::pixelCheck);
    connect(rowChecker, &QCheckBox::stateChanged, this, &MainWindow::rowCheck);
    connect(columnChecker, &QCheckBox::stateChanged, this, &MainWindow::columnCheck);
    connect(gl, &GLVideoWidget::mouseRelease, this, &MainWindow::resetTotal);

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
    if(grabBtn->isChecked()){
        analysisTable->setEnabled(true);
        analysisTable->setStyleSheet("QTableWidget { background-color: #ffffff; color: black; }");
        return;
    }
    analysisTable->setEnabled(false);
    analysisTable->setStyleSheet("QTableWidget { background-color: #f0f0f0; color: gray; }");
}

void MainWindow::onSelectionCompleted(const QPointF &start, const QPointF &end) {
    QTableWidgetItem *xy1 = coordTable->item(0,0);
    QTableWidgetItem *xy2 = coordTable->item(1,0);
    QTableWidgetItem *xy3 = coordTable->item(0,1);
    QTableWidgetItem *xy4 = coordTable->item(1,1);
    xy1->setText(QString("(%1, %2)").arg(start.x()).arg(start.y()));
    xy2->setText(QString("(%1, %2)").arg(end.x()).arg(start.y()));
    xy3->setText(QString("(%1, %2)").arg(start.x()).arg(end.y()));
    xy4->setText(QString("(%1, %2)").arg(end.x()).arg(end.y()));
}

//update data analysis to the table
void MainWindow::updateAnalysis(std::shared_ptr<QVector<int>> grayValues, int selectedWidth, int selectedHeight){
    if (!grayValues || grayValues->isEmpty()) {
        qWarning() << "Received null or empty grayValues!";
        return;
    }
    selectedRegion = grayValues;
    selectedH = selectedHeight;
    selectedW = selectedWidth;

    //min
    if(minChecker-> isChecked())
        minCheck();

    //max
    if(maxChecker-> isChecked())
        maxCheck();

    //mean
    if(averageChecker -> isChecked())
        avegCheck();

    //pixel noise
    if(pixelChecker-> isChecked())
        pixelCheck();

    //row noise
    if(rowChecker -> isChecked())
        rowCheck();

    //column noise
    if(columnChecker -> isChecked())
        columnCheck();



}

//update the minimum
void MainWindow::minCheck(){
    if(!grabBtn -> isChecked() || selectedRegion == nullptr)
        return;
    QTableWidgetItem *minItem = analysisTable->item(0, 1);
    QTableWidgetItem *item = analysisTable->item(0, 3);
    if(!minChecker-> isChecked()){
        minItem->setText(" ");
        item->setText(" ");
        return;
    }
    //frame min
    float minValue = *std::min_element(selectedRegion->begin(), selectedRegion->end());
    minItem->setText(QString::number(minValue));
    //total min
    if(minValue < totalMin)
        totalMin = minValue;
    item->setText(QString::number(totalMin));

}

//update the maximum
void MainWindow::maxCheck(){
    if(!grabBtn -> isChecked() || selectedRegion == nullptr)
        return;
    QTableWidgetItem *maxItem = analysisTable->item(1, 1);
    QTableWidgetItem *item = analysisTable->item(1, 3);
    if(!maxChecker-> isChecked()){
        maxItem->setText(" ");
        item->setText(" ");
        return;
    }
    //frame max
    float maxValue = *std::max_element(selectedRegion->begin(), selectedRegion->end());
    maxItem->setText(QString::number(maxValue));
    //total max
    if(maxValue > totalMax)
        totalMax = maxValue;
    item->setText(QString::number(totalMax));
}

//update the average(mean)
void MainWindow::avegCheck(){
    if(!grabBtn -> isChecked() || selectedRegion == nullptr)
        return;
    QTableWidgetItem *meanItem = analysisTable->item(2, 1);
    QTableWidgetItem *totalMeanItem = analysisTable->item(2, 3);
    if(!averageChecker-> isChecked()){
        meanItem->setText(" ");
        totalMeanItem->setText(" ");
        return;
    }
    //frame mean
    float mean = analysis->meanCal(selectedRegion);
    meanItem->setText(QString::number(mean));
    //total mean
    totalMeanSum += mean;
    totalMeanCounter += 1;
    float totalMean = totalMeanSum/totalMeanCounter;
    totalMeanItem->setText(QString::number(totalMean));
}

//update the pixel noise
void MainWindow::pixelCheck(){
    if(!grabBtn -> isChecked() || selectedRegion == nullptr)
        return;
    QTableWidgetItem *stdDevItem = analysisTable->item(3, 1);
    QTableWidgetItem *item = analysisTable->item(3, 3);
    if(!pixelChecker-> isChecked()){
        stdDevItem->setText(" ");
        item->setText(" ");
        return;
    }
    //frame pixel noise
    float mean = analysis->meanCal(selectedRegion);
    float pixelNoise = analysis->pixelNoiseCal(selectedRegion, mean);
    stdDevItem->setText(QString::number(pixelNoise));
    //total pixel noise
    totalPixelSum += pixelNoise;
    totalPixelCounter += 1;
    float totalPixel = totalPixelSum/totalPixelCounter;
    item->setText(QString::number(totalPixel));
}

//update the row noise
void MainWindow::rowCheck(){
    if(!grabBtn -> isChecked() || selectedRegion == nullptr)
        return;
    QTableWidgetItem *rowItem = analysisTable->item(4, 1);
    QTableWidgetItem *item = analysisTable->item(4, 3);
    if(!rowChecker-> isChecked()){
        rowItem->setText(" ");
        item->setText(" ");
        return;
    }
    //frame row noise
    float rowNoise = analysis->calculateAllRowNoise(selectedRegion, selectedH, selectedW);
    rowItem->setText(QString::number(rowNoise));
    //total row noise
    totalRowSum += rowNoise;
    totalRowCounter += 1;
    float totalRow = totalRowSum / totalRowCounter;
    item->setText(QString::number(totalRow));
}

//update the column noise
void MainWindow::columnCheck(){
    if(!grabBtn -> isChecked() || selectedRegion == nullptr)
        return;
    QTableWidgetItem *columnItem = analysisTable->item(5, 1);
    QTableWidgetItem *item = analysisTable->item(5, 3);
    if(!columnChecker-> isChecked()){
        columnItem->setText(" ");
        item->setText(" ");
        return;
    }
    //frame column noise
    float columnNoise = analysis->calculateAllColumnNoise(selectedRegion, selectedH, selectedW);
    columnItem->setText(QString::number(columnNoise));
    //total column noise
    totalColumnSum += columnNoise;
    totalColumnCounter += 1;
    float totalColumn = totalColumnSum/totalColumnCounter;
    item->setText(QString::number(totalColumn));
}

//reset if re-select the interested region
void MainWindow::resetTotal(){
    totalMin = 256;
    totalMax = -1;
    totalMeanSum = 0;
    totalMeanCounter = 0;
    totalPixelSum = 0.0f;
    totalPixelCounter = 0;
    totalRowCounter = 0;
    totalRowSum = 0.0f;
    totalColumnCounter = 0;
    totalColumnSum = 0.0f;
}




