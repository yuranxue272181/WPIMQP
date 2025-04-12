#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glvideowidget.h"
#include "analysis.h"
#include "graph.h"

//ui
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    layout = ui->mainLayout;
    QWidget * centralWidget = ui->centralwidget;
    centralWidget->setLayout(layout);

    //testchart
    openGraphButton = ui->chart;
    connect(openGraphButton, &QPushButton::clicked, this, &MainWindow::openGraphDialog);

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
    queueSize = 10;
    frameRate = 30;

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
    spin = new QSpinBox();
    spin->setMinimum(3);
    spin->setMaximum(50);
    spin->setValue(10);
    spin->setMinimumSize(70, 25);
    spin->setObjectName("SpinBox");


    //top vboxlayout ui
    QVBoxLayout * mediaLayout = ui ->mediaPlayerLayout;
    QWidget * widgetSpace = new QWidget();
    widgetSpace->setMinimumHeight(20);
    QWidget * widgetSpace2 = new QWidget();
    widgetSpace2->setMinimumHeight(5);
    widgetSpace2->setStyleSheet("background:#393e44;");
    QWidget * widgetSpace3 = new QWidget();
    widgetSpace3->setMinimumHeight(20);
    widgetSpace3->setStyleSheet("background:#393e44;");
    QWidget * widget1 = new QWidget();
    widget1->setStyleSheet("background:#393e44;");
    QWidget * widget2 = new QWidget();
    widget2->setStyleSheet("background:#393e44;");
    QHBoxLayout * topButtons = ui-> topButtons;
    QHBoxLayout * playerLayout = ui->playerLayout;
    widget1 ->setLayout(topButtons);
    widget2 ->setLayout(playerLayout);
    mediaLayout->setSpacing(0);
    mediaLayout->insertWidget(0,widgetSpace);
    mediaLayout->insertWidget(1,widgetSpace2);
    mediaLayout->insertWidget(2,widget1);
    mediaLayout->insertWidget(3,widget2);
    mediaLayout->insertWidget(4,widgetSpace3);



    // widget
    videoWdt = ui->videoWidget;
    QHBoxLayout *layout1 = ui->horizontalLayout_2;
    layout1->addWidget(spin, 0, Qt::AlignTop);

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

    //menu
    menuProject = ui->menuProject;
    menuTool = ui->menuTool;
    menuView = ui->menuView;
    menuEdit = ui-> menuEdit;
    menuRecord = ui-> menuRecord;
    menuHelp = ui->menuHelp;

    //menu action
    //view menu
    QAction *zoomInAction = new QAction(tr("Zoom In"),this);
    QAction *zoomOutAction = new QAction(tr("Zoom Out"),this);
    menuView->addAction(zoomInAction);
    menuView->addAction(zoomOutAction);
    //tool menu
    grabCoAction = new QAction(tr("Grab Coordinates"),this);
    grabCoAction ->setEnabled(false);
    menuTool->addAction(grabCoAction);
    //record menu
    screenshootAction = new QAction(tr("Screen Capture"),this);
    screenshootAction->setEnabled(false);
    recordingAction = new QAction(tr("Video Recording"),this);
    recordingAction->setEnabled(false);
    menuRecord->addAction(screenshootAction);
    menuRecord->addAction(recordingAction);

    //checkBox
    minChecker = new QCheckBox("Minimum");
    //minChecker->setStyleSheet("QCheckBox { margin-left: auto; margin-right: auto; }");
    maxChecker= new QCheckBox("Maximum");
    averageChecker= new QCheckBox("Average");
    rowChecker= new QCheckBox("Row Noise");
    columnChecker= new QCheckBox("Column Noise");
    pixelChecker= new QCheckBox("Pixel Noise");

    //combo box
    frameRateCB = ui->frameRateComboBox;
    frameRateCB->addItem("30");
    frameRateCB->addItem("60");
    frameRateCB->setCurrentText("30");

    //tab widget
    QTabWidget *tabWidget = ui->tabWidget;
    tabWidget->setStyleSheet("background:#393e44;");

    //tab1
    QWidget *tab1 = new QWidget();
    QVBoxLayout *tab1Layout = new QVBoxLayout(tab1);
    tabWidget->addTab(tab1, "Image Enhancement");
    QToolBox *tool1 = ui->toolBox;
    tab1Layout->addWidget(tool1);

    //tab2
    QWidget *tab2 = new QWidget();
    QVBoxLayout *tab2Layout = new QVBoxLayout(tab2);
    tabWidget->addTab(tab2, "Control Component");
    QToolBox *tool2 = ui->toolBox_2;
    tab2Layout->addWidget(tool2);




    //table
    featuresTable = ui->FeatureTable;
    featuresTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // column adaption
    featuresTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch); // row adaption
    featuresTable->setStyleSheet(R"(
    QTableView {
        background-color: #2f3035;
        color: white;
        border: none;
        padding-left: 10px;
        padding-bottom: 10px;
    }

    QTableView::item {
        background-color: #2f3035;
        color: white;
    }

    QHeaderView::section {
        background-color: #2f3035;
        font-weight: bold;
        padding: 2px;
        color: white;
    }

)");

    coordTable = ui->coordinatesTable;
    QStringList rowHeaders;
    rowHeaders << "x1" << "x2";
    coordTable->setVerticalHeaderLabels(rowHeaders);
    coordTable->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    coordTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // column adaption
    coordTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch); // row adaption
    coordTable->setStyleSheet(R"(
        QTableView {
        color: white;
        border: none;
            padding-left: 10px;
            padding-bottom: 10px;
        }

        QTableView::item {
        color: white;
        background-color: #393e44;
        }

        QHeaderView::section {
        background-color: #393e44;
        font-weight: bold;
        padding: 2px;
        color: white;
        }

        QTableCornerButton::section {
        background-color: #393e44;
        }

    )");


    analysisTable = ui->analysisTable;
    analysisTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // column adaption
    analysisTable->horizontalHeader()->setMinimumSectionSize(100);
    analysisTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch); // row adaption
    analysisTable->setStyleSheet(R"(
    QTableView {
        background-color: #393e44;
        color: #51d7d9;
        border: none;
    }

    QTableView::item {
        background-color:#393e44;
        color: white;
    }

    QHeaderView::section {
        background-color: #393e44;
        font-weight: bold;
        padding: 2px;
        color: white;
    }

    QHeaderView::section:disabled {
        background-color:#393e44;
        color: grey;
    }

)");

    analysisTable->setCellWidget(0, 0, minChecker);
    analysisTable->setCellWidget(1, 0, maxChecker);
    analysisTable->setCellWidget(2, 0, averageChecker);
    analysisTable->setCellWidget(3, 0, pixelChecker);
    analysisTable->setCellWidget(4, 0, rowChecker);
    analysisTable->setCellWidget(5, 0, columnChecker);
    analysisTable->setRowHidden(6, true);
    analysisTable->setEnabled(false);
    spin->setEnabled(false);
    frameTemNoise = ui->frameTemNoise;
    frameTemNoise->setStyleSheet("color:grey;");


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


    setButtonIconColor(startBtn, ":/icons/restart.png", QColor(98,212,214));
    setButtonIconColor(playPauseBtn, ":/icons/pause.png", QColor(98,212,214));
    setButtonIconColor(shootBtn, ":/icons/shoot.png", QColor(98,212,214));
    setButtonIconColor(recordBtn, ":/icons/recordGray.png", QColor(98,212,214));
    setButtonIconColor(zoomInBtn, ":/icons/zoomIn.png", QColor(98,212,214));
    setButtonIconColor(zoomOutBtn, ":/icons/zoomOut.png", QColor(98,212,214));

    playPauseBtn->setEnabled(false);
    shootBtn->setEnabled(false);
    recordBtn->setEnabled(false);

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
    connect(spin, &QSpinBox::valueChanged,this,&MainWindow::updateQueueSize);
    connect(frameRateCB, &QComboBox::currentIndexChanged, this, &MainWindow::setFrameRate);
    connect(zoomInAction, &QAction::triggered, this, &MainWindow::zoomIn);
    connect(zoomOutAction, &QAction::triggered, this, &MainWindow::zoomOut);
    connect(grabCoAction, &QAction::triggered, this, &MainWindow::grabBtnChecked);
    connect(screenshootAction, &QAction::triggered, gl, &GLVideoWidget::saveYUVImageDataToFile);
    connect(recordingAction, &QAction::triggered, this, &MainWindow::recordingStatu);

    //updateQueueSize

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
    setButtonIconColor(playPauseBtn, ":/icons/play.png", QColor(98,212,214));
    startBtn->setEnabled(false);
    shootBtn->setEnabled(true);
    recordBtn->setEnabled(true);
    recordingAction->setEnabled(true);
    screenshootAction->setEnabled(true);
    HESlider -> setEnabled(true);
    grabBtn -> setEnabled(true);
    grabCoAction-> setEnabled(true);

    //open the YUV file
    //176x144
    int width=176;
    int height = 144;
    // QFile f(":/mqp_rowing_video.yuv");
    // f.open(QIODevice::ReadOnly);
    // QByteArray data(f.readAll());

    QString fileName = QFileDialog::getOpenFileName(nullptr, "Select YUV File", "", "YUV Files (*.yuv);;All Files (*)");

    if (fileName.isEmpty()) {
        qDebug() << "No file selected.";
        return;
    }
    QFile f(fileName);
    if (!f.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file:" << fileName;
        return;
    }
    QByteArray data = f.readAll();

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
        setButtonIconColor(playPauseBtn, ":/icons/pause.png", QColor(98,212,214));
        recordBtn->setEnabled(false);
        recordingAction->setEnabled(false);
        //HESlider -> setEnabled(false);
    }
    else{
        setButtonIconColor(playPauseBtn, ":/icons/play.png", QColor(98,212,214));
        recordBtn->setEnabled(true);
        recordingAction->setEnabled(true);
        HESlider -> setEnabled(true);
    }
}

// when the video finishes, reset the UI and stop recording
void MainWindow::onVideoFinished(){
    setButtonIconColor(playPauseBtn, ":/icons/pause.png", QColor(98,212,214));
    playPauseBtn->setEnabled(false);
    startBtn->setEnabled(true);
    recordBtn->setEnabled(false);
    recordingAction->setEnabled(false);
    recordBtn->setIcon(QIcon(":/icons/recordGray.png"));
    HESlider -> setEnabled(false);
    gl->stopRecording();

}

// Zoom in the video
void MainWindow::zoomIn(){
    if(zoomFactor<qPow(1.05, 12))
    zoomFactor *= 1.05;
    videoWdt->setFixedSize(352*zoomFactor, 288*zoomFactor);
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
    videoWdt->setFixedSize(352*zoomFactor, 288*zoomFactor);
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
//grab coordinates
void MainWindow::grabBtnChecked(){
    if(grabBtn->isChecked()){
        grabBtn->setChecked(false);
    }else{
        grabBtn->setChecked(true);}
    setTrackingEnabled();

}

//grab coordinates
void MainWindow::setTrackingEnabled(){
    gl -> setTrackingEnabled(grabBtn->isChecked());
    if(grabBtn->isChecked()){
        analysisTable->setEnabled(true);
        frameTemNoise->setStyleSheet("color:#5ad6d9;");
        spin->setEnabled(true);
        return;
    }
    analysisTable->setEnabled(false);
    frameTemNoise->setStyleSheet("color:grey;");
    spin->setEnabled(false);
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
    QTableWidgetItem *tem = analysisTable->item(0, 2);
    if(!minChecker-> isChecked()){
        minItem->setText(" ");
        item->setText(" ");
        tem->setText(" ");
        return;
    }
    //frame min
    float minValue = *std::min_element(selectedRegion->begin(), selectedRegion->end());
    minItem->setText(QString::number(minValue));

    //total min
    if(minValue < totalMin)
        totalMin = minValue;
    //qDebug() << "min" << minValue << "totalMIn" <<totalMin;
    item->setText(QString::number(totalMin));

    //temporal min
    minQ.enqueue(minValue);
    while(minQ.size()>queueSize)
        minQ.dequeue();
    if (minQ.isEmpty())
        return;
    int tempMin = 256;
    for (int i = 0; i < minQ.size(); ++i) {
        int current = minQ.at(i);
        if (current < tempMin) {
            tempMin = current;
        }
    }
    tem->setText(QString::number(tempMin));
}

//update the maximum
void MainWindow::maxCheck(){
    if(!grabBtn -> isChecked() || selectedRegion == nullptr)
        return;
    QTableWidgetItem *maxItem = analysisTable->item(1, 1);
    QTableWidgetItem *item = analysisTable->item(1, 3);
    QTableWidgetItem *tem = analysisTable->item(1, 2);
    if(!maxChecker-> isChecked()){
        maxItem->setText(" ");
        item->setText(" ");
        tem->setText(" ");
        return;
    }
    //frame max
    float maxValue = *std::max_element(selectedRegion->begin(), selectedRegion->end());
    maxItem->setText(QString::number(maxValue));

    //total max
    if(maxValue > totalMax)
        totalMax = maxValue;
    item->setText(QString::number(totalMax));

    //temporal max
    maxQ.enqueue(maxValue);
    while(maxQ.size()>queueSize)
        maxQ.dequeue();
    int tempMax = -1;
    for (int i = 0; i < maxQ.size(); ++i) {
        int current = maxQ.at(i);
        if (current > tempMax) {
            tempMax = current;
        }
    }
    tem->setText(QString::number(tempMax));
}

//update the average(mean)
void MainWindow::avegCheck(){
    if(!grabBtn -> isChecked() || selectedRegion == nullptr)
        return;
    QTableWidgetItem *meanItem = analysisTable->item(2, 1);
    QTableWidgetItem *totalMeanItem = analysisTable->item(2, 3);
    QTableWidgetItem *tem = analysisTable->item(2, 2);
    if(!averageChecker-> isChecked()){
        meanItem->setText(" ");
        totalMeanItem->setText(" ");
        tem->setText(" ");
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

    //temporal mean
    avegQ.enqueue(mean);
    while(avegQ.size()>queueSize)
        avegQ.dequeue();
    float sum = 0;
    for (int i = 0; i < avegQ.size(); ++i) {
        sum += avegQ.at(i);
    }
    float tempMean = sum / avegQ.size();
    tem->setText(QString::number(tempMean));
}

//update the pixel noise
void MainWindow::pixelCheck(){
    if(!grabBtn -> isChecked() || selectedRegion == nullptr)
        return;
    QTableWidgetItem *stdDevItem = analysisTable->item(3, 1);
    QTableWidgetItem *item = analysisTable->item(3, 3);
    QTableWidgetItem *tem = analysisTable->item(3, 2);
    if(!pixelChecker-> isChecked()){
        stdDevItem->setText(" ");
        item->setText(" ");
        tem->setText(" ");
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

    //temporal pixel noise
    pixQ.enqueue(pixelNoise);
    while(pixQ.size()>queueSize)
        pixQ.dequeue();
    float sum = 0;
    for (int i = 0; i < pixQ.size(); ++i) {
        sum += pixQ.at(i);
    }
    float temp = sum / pixQ.size();
    tem->setText(QString::number(temp));
}

//update the row noise
void MainWindow::rowCheck(){
    if(!grabBtn -> isChecked() || selectedRegion == nullptr)
        return;
    QTableWidgetItem *rowItem = analysisTable->item(4, 1);
    QTableWidgetItem *item = analysisTable->item(4, 3);
    QTableWidgetItem *tem = analysisTable->item(4, 2);
    if(!rowChecker-> isChecked()){
        rowItem->setText(" ");
        item->setText(" ");
        tem->setText(" ");
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
    //tempiral row noise
    rowQ.enqueue(rowNoise);
    while(rowQ.size()>queueSize)
        rowQ.dequeue();
    float sum = 0;
    for (int i = 0; i < rowQ.size(); ++i) {
        sum += rowQ.at(i);
    }
    float temp = sum / rowQ.size();
    tem->setText(QString::number(temp));
}

//update the column noise
void MainWindow::columnCheck(){
    if(!grabBtn -> isChecked() || selectedRegion == nullptr)
        return;
    QTableWidgetItem *columnItem = analysisTable->item(5, 1);
    QTableWidgetItem *item = analysisTable->item(5, 3);
    QTableWidgetItem *tem = analysisTable->item(5, 2);
    if(!columnChecker-> isChecked()){
        columnItem->setText(" ");
        item->setText(" ");
        tem->setText(" ");
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

    //temporal column noise
    colQ.enqueue(columnNoise);
    while(colQ.size()>queueSize)
        colQ.dequeue();
    float sum = 0;
    for (int i = 0; i < colQ.size(); ++i) {
        sum += colQ.at(i);
    }
    float temp = sum / colQ.size();
    tem->setText(QString::number(temp));
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
    minQ.clear();
    maxQ.clear();
    avegQ.clear();
    rowQ.clear();
    colQ.clear();
    pixQ.clear();

}
//update the size of temporal noise
void MainWindow::updateQueueSize(int value){
    queueSize = value;
}

//update the frame rate from the user inteface
//Here's the interface to the board about frame rate, the frame rate is stored in <frameRate>, with number 30, or 60
void MainWindow::setFrameRate(int index){
    frameRate = (frameRateCB->itemText(index)).toInt();
    gl->setFrameRate(frameRate);

}

//update the frame rate from the board
void MainWindow::setFrameRateFromBoard(int value){
    switch (value) {
        case 30:
            frameRate = value;
            frameRateCB->setCurrentText("30");
            gl->setFrameRate(frameRate);
            break;
        case 60:
            frameRate = value;
            frameRateCB->setCurrentText("60");
            gl->setFrameRate(frameRate);
            break;
        default:
            qDebug()<<"Unsupported frame rate: "<<value;
            break;
    }
}

//testchart
void MainWindow::openGraphDialog()
{
    GraphDialog *dialog = new GraphDialog(this);
    dialog->exec();  // open
}

//button icon color set
void MainWindow::setButtonIconColor(QToolButton *button, const QString &iconPath, const QColor &color)
{
    QIcon originalIcon(iconPath);

    QPixmap pixmap = originalIcon.pixmap(QSize(30, 30));

    QPainter painter(&pixmap);

    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);

    painter.fillRect(pixmap.rect(), color);

    painter.end();

    button->setIcon(QIcon(pixmap));
    button->setIconSize(QSize(30, 30));
}




