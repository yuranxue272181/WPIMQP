/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *videoWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *startButton;
    QToolButton *playPauseButton;
    QToolButton *shootButton;
    QToolButton *recordButton;
    QToolButton *zoomInButton;
    QToolButton *zoomOutButton;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QTableWidget *analysisTable;
    QWidget *tab_5;
    QTextBrowser *textBrowser;
    QLabel *label;
    QLabel *label_2;
    QTableWidget *FeatureTable;
    QTabWidget *tabWidget;
    QWidget *tab;
    QToolBox *toolBox;
    QWidget *page;
    QSlider *BrightnessSlider;
    QLabel *brightness;
    QWidget *page_2;
    QSlider *ContrastSlider;
    QLabel *contrast;
    QWidget *Sharpeness;
    QSlider *SharpnessSlider;
    QLabel *sharpness;
    QWidget *page_3;
    QSlider *HESlider;
    QLabel *HE;
    QWidget *page_4;
    QSlider *NRSlider;
    QLabel *NR;
    QWidget *page_7;
    QSlider *GammaSlider;
    QLabel *Gamma;
    QWidget *page_8;
    QPushButton *resetButton;
    QWidget *tab_3;
    QToolBox *toolBox_2;
    QWidget *page_5;
    QSlider *exposureTimeSlider;
    QLabel *exposureTime;
    QWidget *page_6;
    QSlider *gainSlider;
    QLabel *gain;
    QWidget *Sharpen_2;
    QSlider *dynamicRangeSlider;
    QLabel *dynamicRange;
    QWidget *page_9;
    QSlider *STNRSlider;
    QLabel *STNR;
    QWidget *widget;
    QPushButton *grabButton;
    QTableWidget *coordinatesTable;
    QMenuBar *menuBar;
    QMenu *menuhe_p;
    QMenu *menuCollection;
    QMenu *menuEdit;
    QMenu *menuRecord;
    QMenu *menuHelp;
    QMenu *menuView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 582);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setSizeIncrement(QSize(10, 10));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setBold(false);
        centralwidget->setFont(font);
        videoWidget = new QWidget(centralwidget);
        videoWidget->setObjectName("videoWidget");
        videoWidget->setGeometry(QRect(210, 40, 352, 288));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(videoWidget->sizePolicy().hasHeightForWidth());
        videoWidget->setSizePolicy(sizePolicy1);
        videoWidget->setMinimumSize(QSize(352, 288));
        videoWidget->setMaximumSize(QSize(1056, 864));
        videoWidget->setSizeIncrement(QSize(0, 0));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(200, 5, 371, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        startButton = new QToolButton(layoutWidget);
        startButton->setObjectName("startButton");
        startButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(startButton);

        playPauseButton = new QToolButton(layoutWidget);
        playPauseButton->setObjectName("playPauseButton");
        playPauseButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(playPauseButton);

        shootButton = new QToolButton(layoutWidget);
        shootButton->setObjectName("shootButton");
        shootButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(shootButton);

        recordButton = new QToolButton(layoutWidget);
        recordButton->setObjectName("recordButton");
        recordButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(recordButton);

        zoomInButton = new QToolButton(layoutWidget);
        zoomInButton->setObjectName("zoomInButton");
        zoomInButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(zoomInButton);

        zoomOutButton = new QToolButton(layoutWidget);
        zoomOutButton->setObjectName("zoomOutButton");
        zoomOutButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(zoomOutButton);

        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(290, 360, 271, 191));
        tabWidget_2->setMinimumSize(QSize(0, 140));
        tabWidget_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        analysisTable = new QTableWidget(tab_4);
        if (analysisTable->columnCount() < 2)
            analysisTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        analysisTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        analysisTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (analysisTable->rowCount() < 7)
            analysisTable->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(0, 0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(0, 1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(1, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(1, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(2, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(2, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(3, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(3, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(4, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(4, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(5, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(5, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(6, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(6, 1, __qtablewidgetitem15);
        analysisTable->setObjectName("analysisTable");
        analysisTable->setGeometry(QRect(0, 0, 271, 161));
        analysisTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        textBrowser = new QTextBrowser(tab_5);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(0, 0, 321, 191));
        textBrowser->setMinimumSize(QSize(321, 101));
        tabWidget_2->addTab(tab_5, QString());
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(410, 330, 49, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(500, 330, 49, 16));
        FeatureTable = new QTableWidget(centralwidget);
        if (FeatureTable->columnCount() < 2)
            FeatureTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        FeatureTable->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        FeatureTable->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        if (FeatureTable->rowCount() < 10)
            FeatureTable->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(0, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(0, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(1, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(1, 1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(2, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(2, 1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(3, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(3, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(4, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(4, 1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(5, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(5, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(6, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(6, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(7, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(7, 1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(8, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(8, 1, __qtablewidgetitem35);
        QFont font1;
        font1.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem36->setFont(font1);
        FeatureTable->setItem(9, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(9, 1, __qtablewidgetitem37);
        FeatureTable->setObjectName("FeatureTable");
        FeatureTable->setGeometry(QRect(0, 0, 201, 341));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(FeatureTable->sizePolicy().hasHeightForWidth());
        FeatureTable->setSizePolicy(sizePolicy2);
        FeatureTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        FeatureTable->horizontalHeader()->setHighlightSections(true);
        FeatureTable->verticalHeader()->setVisible(false);
        FeatureTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(590, 10, 201, 311));
        tabWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName("tab");
        toolBox = new QToolBox(tab);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(10, 10, 181, 271));
        toolBox->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 100, 30));
        BrightnessSlider = new QSlider(page);
        BrightnessSlider->setObjectName("BrightnessSlider");
        BrightnessSlider->setGeometry(QRect(0, 10, 151, 22));
        BrightnessSlider->setOrientation(Qt::Orientation::Horizontal);
        brightness = new QLabel(page);
        brightness->setObjectName("brightness");
        brightness->setGeometry(QRect(150, 10, 31, 21));
        brightness->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox->addItem(page, QString::fromUtf8("Brightness"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 181, 61));
        ContrastSlider = new QSlider(page_2);
        ContrastSlider->setObjectName("ContrastSlider");
        ContrastSlider->setGeometry(QRect(0, 10, 151, 22));
        ContrastSlider->setOrientation(Qt::Orientation::Horizontal);
        contrast = new QLabel(page_2);
        contrast->setObjectName("contrast");
        contrast->setGeometry(QRect(150, 10, 31, 21));
        contrast->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox->addItem(page_2, QString::fromUtf8("Contrast"));
        Sharpeness = new QWidget();
        Sharpeness->setObjectName("Sharpeness");
        Sharpeness->setGeometry(QRect(0, 0, 100, 30));
        SharpnessSlider = new QSlider(Sharpeness);
        SharpnessSlider->setObjectName("SharpnessSlider");
        SharpnessSlider->setGeometry(QRect(0, 10, 151, 22));
        SharpnessSlider->setOrientation(Qt::Orientation::Horizontal);
        sharpness = new QLabel(Sharpeness);
        sharpness->setObjectName("sharpness");
        sharpness->setGeometry(QRect(150, 10, 31, 21));
        sharpness->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox->addItem(Sharpeness, QString::fromUtf8("Sharpeness"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setGeometry(QRect(0, 0, 100, 30));
        HESlider = new QSlider(page_3);
        HESlider->setObjectName("HESlider");
        HESlider->setGeometry(QRect(0, 20, 151, 22));
        HESlider->setOrientation(Qt::Orientation::Horizontal);
        HE = new QLabel(page_3);
        HE->setObjectName("HE");
        HE->setGeometry(QRect(150, 20, 31, 21));
        HE->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox->addItem(page_3, QString::fromUtf8("Histogram Equalization"));
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        page_4->setGeometry(QRect(0, 0, 100, 30));
        NRSlider = new QSlider(page_4);
        NRSlider->setObjectName("NRSlider");
        NRSlider->setGeometry(QRect(0, 10, 151, 22));
        NRSlider->setOrientation(Qt::Orientation::Horizontal);
        NR = new QLabel(page_4);
        NR->setObjectName("NR");
        NR->setGeometry(QRect(150, 10, 31, 21));
        NR->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox->addItem(page_4, QString::fromUtf8("Noise Reduction"));
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        page_7->setGeometry(QRect(0, 0, 100, 30));
        GammaSlider = new QSlider(page_7);
        GammaSlider->setObjectName("GammaSlider");
        GammaSlider->setGeometry(QRect(0, 10, 151, 22));
        GammaSlider->setOrientation(Qt::Orientation::Horizontal);
        Gamma = new QLabel(page_7);
        Gamma->setObjectName("Gamma");
        Gamma->setGeometry(QRect(150, 10, 31, 21));
        Gamma->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox->addItem(page_7, QString::fromUtf8("Gamma Correction"));
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        page_8->setGeometry(QRect(0, 0, 100, 30));
        resetButton = new QPushButton(page_8);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(20, 0, 75, 24));
        toolBox->addItem(page_8, QString::fromUtf8("Reset to Default"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        toolBox_2 = new QToolBox(tab_3);
        toolBox_2->setObjectName("toolBox_2");
        toolBox_2->setGeometry(QRect(10, 14, 181, 271));
        toolBox_2->setStyleSheet(QString::fromUtf8(""));
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        page_5->setGeometry(QRect(0, 0, 100, 30));
        exposureTimeSlider = new QSlider(page_5);
        exposureTimeSlider->setObjectName("exposureTimeSlider");
        exposureTimeSlider->setGeometry(QRect(0, 10, 151, 22));
        exposureTimeSlider->setOrientation(Qt::Orientation::Horizontal);
        exposureTime = new QLabel(page_5);
        exposureTime->setObjectName("exposureTime");
        exposureTime->setGeometry(QRect(150, 10, 31, 21));
        exposureTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox_2->addItem(page_5, QString::fromUtf8("Exposure Time"));
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        page_6->setGeometry(QRect(0, 0, 181, 151));
        gainSlider = new QSlider(page_6);
        gainSlider->setObjectName("gainSlider");
        gainSlider->setGeometry(QRect(0, 10, 151, 22));
        gainSlider->setOrientation(Qt::Orientation::Horizontal);
        gain = new QLabel(page_6);
        gain->setObjectName("gain");
        gain->setGeometry(QRect(150, 10, 31, 21));
        gain->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox_2->addItem(page_6, QString::fromUtf8("Gain"));
        Sharpen_2 = new QWidget();
        Sharpen_2->setObjectName("Sharpen_2");
        Sharpen_2->setGeometry(QRect(0, 0, 100, 30));
        dynamicRangeSlider = new QSlider(Sharpen_2);
        dynamicRangeSlider->setObjectName("dynamicRangeSlider");
        dynamicRangeSlider->setGeometry(QRect(0, 10, 151, 22));
        dynamicRangeSlider->setOrientation(Qt::Orientation::Horizontal);
        dynamicRange = new QLabel(Sharpen_2);
        dynamicRange->setObjectName("dynamicRange");
        dynamicRange->setGeometry(QRect(150, 10, 31, 21));
        dynamicRange->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox_2->addItem(Sharpen_2, QString::fromUtf8("Dynamic Range"));
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        page_9->setGeometry(QRect(0, 0, 181, 151));
        STNRSlider = new QSlider(page_9);
        STNRSlider->setObjectName("STNRSlider");
        STNRSlider->setGeometry(QRect(0, 10, 151, 22));
        STNRSlider->setOrientation(Qt::Orientation::Horizontal);
        STNR = new QLabel(page_9);
        STNR->setObjectName("STNR");
        STNR->setGeometry(QRect(150, 10, 31, 21));
        STNR->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(page_9);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 0, 211, 201));
        toolBox_2->addItem(page_9, QString::fromUtf8("Signal-to-Noise Ratio"));
        tabWidget->addTab(tab_3, QString());
        grabButton = new QPushButton(centralwidget);
        grabButton->setObjectName("grabButton");
        grabButton->setGeometry(QRect(620, 350, 131, 24));
        coordinatesTable = new QTableWidget(centralwidget);
        if (coordinatesTable->columnCount() < 2)
            coordinatesTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        coordinatesTable->setHorizontalHeaderItem(0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        coordinatesTable->setHorizontalHeaderItem(1, __qtablewidgetitem39);
        if (coordinatesTable->rowCount() < 4)
            coordinatesTable->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setTextAlignment(Qt::AlignCenter);
        coordinatesTable->setItem(0, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setTextAlignment(Qt::AlignCenter);
        coordinatesTable->setItem(0, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setTextAlignment(Qt::AlignCenter);
        coordinatesTable->setItem(1, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setTextAlignment(Qt::AlignCenter);
        coordinatesTable->setItem(1, 1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setTextAlignment(Qt::AlignCenter);
        coordinatesTable->setItem(2, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setTextAlignment(Qt::AlignCenter);
        coordinatesTable->setItem(2, 1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setTextAlignment(Qt::AlignCenter);
        coordinatesTable->setItem(3, 0, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setTextAlignment(Qt::AlignCenter);
        coordinatesTable->setItem(3, 1, __qtablewidgetitem47);
        coordinatesTable->setObjectName("coordinatesTable");
        coordinatesTable->setGeometry(QRect(580, 380, 211, 151));
        coordinatesTable->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked|QAbstractItemView::EditTrigger::EditKeyPressed);
        coordinatesTable->horizontalHeader()->setVisible(true);
        coordinatesTable->horizontalHeader()->setCascadingSectionResizes(false);
        coordinatesTable->horizontalHeader()->setHighlightSections(false);
        coordinatesTable->verticalHeader()->setVisible(false);
        MainWindow->setCentralWidget(centralwidget);
        tabWidget_2->raise();
        videoWidget->raise();
        layoutWidget->raise();
        label->raise();
        label_2->raise();
        FeatureTable->raise();
        tabWidget->raise();
        grabButton->raise();
        coordinatesTable->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menuhe_p = new QMenu(menuBar);
        menuhe_p->setObjectName("menuhe_p");
        menuCollection = new QMenu(menuBar);
        menuCollection->setObjectName("menuCollection");
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName("menuEdit");
        menuRecord = new QMenu(menuBar);
        menuRecord->setObjectName("menuRecord");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        menuView = new QMenu(menuBar);
        menuView->setObjectName("menuView");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuhe_p->menuAction());
        menuBar->addAction(menuCollection->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuRecord->menuAction());
        menuBar->addAction(menuHelp->menuAction());

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);
        toolBox->setCurrentIndex(1);
        toolBox_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QString());
        playPauseButton->setText(QString());
        shootButton->setText(QString());
        recordButton->setText(QString());
        zoomInButton->setText(QString());
        zoomOutButton->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = analysisTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Analysis", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = analysisTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));

        const bool __sortingEnabled = analysisTable->isSortingEnabled();
        analysisTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem2 = analysisTable->item(0, 0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = analysisTable->item(1, 0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = analysisTable->item(2, 0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Average", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = analysisTable->item(3, 0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Pixel Noise", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = analysisTable->item(4, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Row Noise", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = analysisTable->item(5, 0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Column Noise", nullptr));
        analysisTable->setSortingEnabled(__sortingEnabled);

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "ROI Grayscale Analysis", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI';\">Camera 1:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI';\">  connecting</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span s"
                        "tyle=\" font-family:'Microsoft YaHei UI';\">  1000x1000</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI';\">   etc</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI';\">Camera 2:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI';\">  disconnecting</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Microsoft YaHei UI';\"><br /></p></body></html>", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Device Connection", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "176x144", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "30fps", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = FeatureTable->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Property", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = FeatureTable->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));

        const bool __sortingEnabled1 = FeatureTable->isSortingEnabled();
        FeatureTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem10 = FeatureTable->item(0, 0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = FeatureTable->item(0, 1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = FeatureTable->item(1, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = FeatureTable->item(1, 1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = FeatureTable->item(2, 0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Sharpness", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = FeatureTable->item(2, 1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = FeatureTable->item(3, 0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "HIstogram Equalization", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = FeatureTable->item(3, 1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = FeatureTable->item(4, 0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Noise Reduction", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = FeatureTable->item(4, 1);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = FeatureTable->item(5, 0);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Gamma Correction", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = FeatureTable->item(5, 1);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = FeatureTable->item(6, 0);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Exposure Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = FeatureTable->item(6, 1);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = FeatureTable->item(7, 0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "Gain", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = FeatureTable->item(7, 1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = FeatureTable->item(8, 0);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Dynamic Range", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = FeatureTable->item(8, 1);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = FeatureTable->item(9, 0);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "Signal-to-Noise Ratio", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = FeatureTable->item(9, 1);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        FeatureTable->setSortingEnabled(__sortingEnabled1);

        brightness->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        contrast->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        sharpness->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        toolBox->setItemText(toolBox->indexOf(Sharpeness), QCoreApplication::translate("MainWindow", "Sharpeness", nullptr));
        HE->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "Histogram Equalization", nullptr));
        NR->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("MainWindow", "Noise Reduction", nullptr));
        Gamma->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_7), QCoreApplication::translate("MainWindow", "Gamma Correction", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_8), QCoreApplication::translate("MainWindow", "Reset to Default", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "   Image Enhancement", nullptr));
        exposureTime->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(page_5), QCoreApplication::translate("MainWindow", "Exposure Time", nullptr));
        gain->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(page_6), QCoreApplication::translate("MainWindow", "Gain", nullptr));
        dynamicRange->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(Sharpen_2), QCoreApplication::translate("MainWindow", "Dynamic Range", nullptr));
        STNR->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(page_9), QCoreApplication::translate("MainWindow", "Signal-to-Noise Ratio", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Control Component", nullptr));
        grabButton->setText(QCoreApplication::translate("MainWindow", "Grab Coordinates", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = coordinatesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "Qx", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = coordinatesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "Qy", nullptr));

        const bool __sortingEnabled2 = coordinatesTable->isSortingEnabled();
        coordinatesTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem32 = coordinatesTable->item(0, 0);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = coordinatesTable->item(0, 1);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = coordinatesTable->item(1, 0);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = coordinatesTable->item(1, 1);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = coordinatesTable->item(2, 0);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = coordinatesTable->item(2, 1);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = coordinatesTable->item(3, 0);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = coordinatesTable->item(3, 1);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        coordinatesTable->setSortingEnabled(__sortingEnabled2);

        menuhe_p->setTitle(QCoreApplication::translate("MainWindow", "Project", nullptr));
        menuCollection->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuRecord->setTitle(QCoreApplication::translate("MainWindow", "Record", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
