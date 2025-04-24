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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *mainLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QTableWidget *FeatureTable;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *mediaPlayerLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QLabel *frameTemNoise;
    QTableWidget *analysisTable;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_7;
    QStackedWidget *stackedWidget;
    QVBoxLayout *verticalLayout_4;
    QPushButton *grabButton;
    QTableWidget *coordinatesTable;
    QWidget *widget_6;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_5;
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
    QWidget *layoutWidget;
    QHBoxLayout *playerLayout;
    QSpacerItem *horizontalSpacer_2;
    QWidget *videoWidget;
    QSpacerItem *horizontalSpacer_3;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *topButtons;
    QToolButton *startButton;
    QToolButton *playPauseButton;
    QToolButton *shootButton;
    QToolButton *recordButton;
    QToolButton *zoomInButton;
    QToolButton *zoomOutButton;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_8;
    QMenuBar *menuBar;
    QMenu *menuProject;
    QMenu *menuTool;
    QMenu *menuRecord;
    QMenu *menuHelp;
    QMenu *menuView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1207, 655);
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
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(0, 0, 851, 581));
        mainLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");

        mainLayout->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        FeatureTable = new QTableWidget(horizontalLayoutWidget_3);
        if (FeatureTable->columnCount() < 2)
            FeatureTable->setColumnCount(2);
        QBrush brush(QColor(81, 216, 219, 255));
        brush.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(47, 48, 53));
        __qtablewidgetitem->setForeground(brush);
        FeatureTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QBrush brush1(QColor(81, 216, 219, 255));
        brush1.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setBackground(QColor(47, 48, 53));
        __qtablewidgetitem1->setForeground(brush1);
        FeatureTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (FeatureTable->rowCount() < 10)
            FeatureTable->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(0, 0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(0, 1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(1, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(1, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(2, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(2, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(3, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(3, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(4, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(4, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(5, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(5, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(6, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(6, 1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(7, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(7, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(8, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(8, 1, __qtablewidgetitem19);
        QFont font1;
        font1.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem20->setFont(font1);
        FeatureTable->setItem(9, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignCenter);
        FeatureTable->setItem(9, 1, __qtablewidgetitem21);
        FeatureTable->setObjectName("FeatureTable");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(FeatureTable->sizePolicy().hasHeightForWidth());
        FeatureTable->setSizePolicy(sizePolicy1);
        FeatureTable->setMinimumSize(QSize(160, 0));
        FeatureTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        FeatureTable->setShowGrid(false);
        FeatureTable->setGridStyle(Qt::PenStyle::NoPen);
        FeatureTable->setSortingEnabled(false);
        FeatureTable->horizontalHeader()->setHighlightSections(true);
        FeatureTable->verticalHeader()->setVisible(false);
        FeatureTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        verticalLayout->addWidget(FeatureTable);


        mainLayout->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        widget_4 = new QWidget(horizontalLayoutWidget_3);
        widget_4->setObjectName("widget_4");
        widget_4->setMinimumSize(QSize(20, 0));

        horizontalLayout_3->addWidget(widget_4);


        mainLayout->addLayout(horizontalLayout_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        mediaPlayerLayout = new QVBoxLayout();
        mediaPlayerLayout->setObjectName("mediaPlayerLayout");

        verticalLayout_3->addLayout(mediaPlayerLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget_3 = new QWidget(horizontalLayoutWidget_3);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(10, 0));

        horizontalLayout_2->addWidget(widget_3);

        label_5 = new QLabel(horizontalLayoutWidget_3);
        label_5->setObjectName("label_5");

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        frameTemNoise = new QLabel(horizontalLayoutWidget_3);
        frameTemNoise->setObjectName("frameTemNoise");
        frameTemNoise->setMinimumSize(QSize(160, 0));
        frameTemNoise->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(frameTemNoise);


        verticalLayout_2->addLayout(horizontalLayout_2);

        analysisTable = new QTableWidget(horizontalLayoutWidget_3);
        if (analysisTable->columnCount() < 4)
            analysisTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font);
        analysisTable->setHorizontalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font);
        analysisTable->setHorizontalHeaderItem(1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font);
        analysisTable->setHorizontalHeaderItem(2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font);
        analysisTable->setHorizontalHeaderItem(3, __qtablewidgetitem25);
        if (analysisTable->rowCount() < 7)
            analysisTable->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(0, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(0, 1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(0, 2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(0, 3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(1, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(1, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(1, 2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(1, 3, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(2, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(2, 1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(2, 2, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(2, 3, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(3, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(3, 1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(3, 2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(3, 3, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(4, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(4, 1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(4, 2, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(4, 3, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(5, 0, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(5, 1, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(5, 2, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        __qtablewidgetitem49->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(5, 3, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(6, 0, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(6, 1, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        __qtablewidgetitem52->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(6, 2, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        __qtablewidgetitem53->setTextAlignment(Qt::AlignCenter);
        analysisTable->setItem(6, 3, __qtablewidgetitem53);
        analysisTable->setObjectName("analysisTable");
        analysisTable->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(analysisTable->sizePolicy().hasHeightForWidth());
        analysisTable->setSizePolicy(sizePolicy2);
        analysisTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        analysisTable->setShowGrid(true);
        analysisTable->setGridStyle(Qt::PenStyle::SolidLine);
        analysisTable->horizontalHeader()->setDefaultSectionSize(90);
        analysisTable->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(analysisTable);

        widget = new QWidget(horizontalLayoutWidget_3);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 10));

        verticalLayout_2->addWidget(widget);


        verticalLayout_3->addLayout(verticalLayout_2);


        mainLayout->addLayout(verticalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        widget_5 = new QWidget(horizontalLayoutWidget_3);
        widget_5->setObjectName("widget_5");
        widget_5->setMinimumSize(QSize(10, 0));

        horizontalLayout_7->addWidget(widget_5);


        mainLayout->addLayout(horizontalLayout_7);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        widget_7 = new QWidget(horizontalLayoutWidget_3);
        widget_7->setObjectName("widget_7");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy3);
        widget_7->setMinimumSize(QSize(0, 15));

        verticalLayout_5->addWidget(widget_7);

        stackedWidget = new QStackedWidget(horizontalLayoutWidget_3);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy4);
        stackedWidget->setMinimumSize(QSize(0, 280));
        stackedWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        stackedWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(stackedWidget);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        grabButton = new QPushButton(horizontalLayoutWidget_3);
        grabButton->setObjectName("grabButton");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(grabButton->sizePolicy().hasHeightForWidth());
        grabButton->setSizePolicy(sizePolicy5);
        grabButton->setMinimumSize(QSize(158, 0));
        grabButton->setCheckable(true);

        verticalLayout_4->addWidget(grabButton);

        coordinatesTable = new QTableWidget(horizontalLayoutWidget_3);
        if (coordinatesTable->columnCount() < 2)
            coordinatesTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        coordinatesTable->setHorizontalHeaderItem(0, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        coordinatesTable->setHorizontalHeaderItem(1, __qtablewidgetitem55);
        if (coordinatesTable->rowCount() < 2)
            coordinatesTable->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        __qtablewidgetitem56->setTextAlignment(Qt::AlignCenter);
        coordinatesTable->setItem(0, 0, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        __qtablewidgetitem57->setTextAlignment(Qt::AlignCenter);
        coordinatesTable->setItem(0, 1, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        __qtablewidgetitem58->setTextAlignment(Qt::AlignCenter);
        coordinatesTable->setItem(1, 0, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        __qtablewidgetitem59->setTextAlignment(Qt::AlignCenter);
        coordinatesTable->setItem(1, 1, __qtablewidgetitem59);
        coordinatesTable->setObjectName("coordinatesTable");
        coordinatesTable->setEnabled(true);
        sizePolicy4.setHeightForWidth(coordinatesTable->sizePolicy().hasHeightForWidth());
        coordinatesTable->setSizePolicy(sizePolicy4);
        coordinatesTable->setMaximumSize(QSize(16777215, 16777215));
        coordinatesTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        coordinatesTable->setRowCount(2);
        coordinatesTable->horizontalHeader()->setVisible(true);
        coordinatesTable->horizontalHeader()->setCascadingSectionResizes(false);
        coordinatesTable->horizontalHeader()->setMinimumSectionSize(60);
        coordinatesTable->horizontalHeader()->setDefaultSectionSize(80);
        coordinatesTable->horizontalHeader()->setHighlightSections(false);
        coordinatesTable->verticalHeader()->setVisible(true);
        coordinatesTable->verticalHeader()->setDefaultSectionSize(40);

        verticalLayout_4->addWidget(coordinatesTable);

        widget_6 = new QWidget(horizontalLayoutWidget_3);
        widget_6->setObjectName("widget_6");
        widget_6->setMinimumSize(QSize(0, 10));

        verticalLayout_4->addWidget(widget_6);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_5->setStretch(2, 2);

        mainLayout->addLayout(verticalLayout_5);

        widget_2 = new QWidget(horizontalLayoutWidget_3);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(20, 0));

        mainLayout->addWidget(widget_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");

        mainLayout->addLayout(horizontalLayout_5);

        mainLayout->setStretch(3, 2);
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(950, 330, 251, 241));
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        toolBox->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 251, 38));
        BrightnessSlider = new QSlider(page);
        BrightnessSlider->setObjectName("BrightnessSlider");
        BrightnessSlider->setGeometry(QRect(0, 10, 200, 22));
        BrightnessSlider->setOrientation(Qt::Orientation::Horizontal);
        brightness = new QLabel(page);
        brightness->setObjectName("brightness");
        brightness->setGeometry(QRect(200, 10, 31, 21));
        brightness->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox->addItem(page, QString::fromUtf8("Brightness"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 251, 38));
        ContrastSlider = new QSlider(page_2);
        ContrastSlider->setObjectName("ContrastSlider");
        ContrastSlider->setGeometry(QRect(0, 10, 200, 22));
        ContrastSlider->setOrientation(Qt::Orientation::Horizontal);
        contrast = new QLabel(page_2);
        contrast->setObjectName("contrast");
        contrast->setGeometry(QRect(200, 10, 31, 21));
        contrast->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox->addItem(page_2, QString::fromUtf8("Contrast"));
        Sharpeness = new QWidget();
        Sharpeness->setObjectName("Sharpeness");
        Sharpeness->setGeometry(QRect(0, 0, 251, 38));
        SharpnessSlider = new QSlider(Sharpeness);
        SharpnessSlider->setObjectName("SharpnessSlider");
        SharpnessSlider->setGeometry(QRect(0, 10, 200, 22));
        SharpnessSlider->setOrientation(Qt::Orientation::Horizontal);
        sharpness = new QLabel(Sharpeness);
        sharpness->setObjectName("sharpness");
        sharpness->setGeometry(QRect(200, 10, 31, 21));
        sharpness->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox->addItem(Sharpeness, QString::fromUtf8("Sharpeness"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setGeometry(QRect(0, 0, 251, 38));
        HESlider = new QSlider(page_3);
        HESlider->setObjectName("HESlider");
        HESlider->setGeometry(QRect(0, 20, 200, 22));
        HESlider->setOrientation(Qt::Orientation::Horizontal);
        HE = new QLabel(page_3);
        HE->setObjectName("HE");
        HE->setGeometry(QRect(200, 20, 31, 21));
        HE->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox->addItem(page_3, QString::fromUtf8("Histogram Equalization"));
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        page_4->setGeometry(QRect(0, 0, 251, 38));
        NRSlider = new QSlider(page_4);
        NRSlider->setObjectName("NRSlider");
        NRSlider->setGeometry(QRect(0, 10, 200, 22));
        NRSlider->setOrientation(Qt::Orientation::Horizontal);
        NR = new QLabel(page_4);
        NR->setObjectName("NR");
        NR->setGeometry(QRect(200, 10, 31, 21));
        NR->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox->addItem(page_4, QString::fromUtf8("Noise Reduction"));
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        page_7->setGeometry(QRect(0, 0, 251, 38));
        GammaSlider = new QSlider(page_7);
        GammaSlider->setObjectName("GammaSlider");
        GammaSlider->setGeometry(QRect(0, 10, 200, 22));
        GammaSlider->setOrientation(Qt::Orientation::Horizontal);
        Gamma = new QLabel(page_7);
        Gamma->setObjectName("Gamma");
        Gamma->setGeometry(QRect(200, 10, 31, 21));
        Gamma->setAlignment(Qt::AlignmentFlag::AlignCenter);
        toolBox->addItem(page_7, QString::fromUtf8("Gamma Correction"));
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        page_8->setGeometry(QRect(0, 0, 251, 38));
        resetButton = new QPushButton(page_8);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(0, 0, 201, 24));
        toolBox->addItem(page_8, QString::fromUtf8("Reset to Default"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(1000, 0, 379, 290));
        playerLayout = new QHBoxLayout(layoutWidget);
        playerLayout->setObjectName("playerLayout");
        playerLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        playerLayout->addItem(horizontalSpacer_2);

        videoWidget = new QWidget(layoutWidget);
        videoWidget->setObjectName("videoWidget");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(videoWidget->sizePolicy().hasHeightForWidth());
        videoWidget->setSizePolicy(sizePolicy6);
        videoWidget->setMinimumSize(QSize(352, 288));
        videoWidget->setMaximumSize(QSize(2040, 1960));
        videoWidget->setSizeIncrement(QSize(0, 0));

        playerLayout->addWidget(videoWidget);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        playerLayout->addItem(horizontalSpacer_3);

        horizontalLayoutWidget_4 = new QWidget(centralwidget);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(980, 300, 259, 32));
        topButtons = new QHBoxLayout(horizontalLayoutWidget_4);
        topButtons->setObjectName("topButtons");
        topButtons->setContentsMargins(0, 0, 0, 0);
        startButton = new QToolButton(horizontalLayoutWidget_4);
        startButton->setObjectName("startButton");
        startButton->setMinimumSize(QSize(30, 30));

        topButtons->addWidget(startButton);

        playPauseButton = new QToolButton(horizontalLayoutWidget_4);
        playPauseButton->setObjectName("playPauseButton");
        playPauseButton->setMinimumSize(QSize(30, 30));

        topButtons->addWidget(playPauseButton);

        shootButton = new QToolButton(horizontalLayoutWidget_4);
        shootButton->setObjectName("shootButton");
        shootButton->setMinimumSize(QSize(30, 30));

        topButtons->addWidget(shootButton);

        recordButton = new QToolButton(horizontalLayoutWidget_4);
        recordButton->setObjectName("recordButton");
        recordButton->setMinimumSize(QSize(30, 30));

        topButtons->addWidget(recordButton);

        zoomInButton = new QToolButton(horizontalLayoutWidget_4);
        zoomInButton->setObjectName("zoomInButton");
        zoomInButton->setMinimumSize(QSize(30, 30));

        topButtons->addWidget(zoomInButton);

        zoomOutButton = new QToolButton(horizontalLayoutWidget_4);
        zoomOutButton->setObjectName("zoomOutButton");
        zoomOutButton->setMinimumSize(QSize(30, 30));

        topButtons->addWidget(zoomOutButton);

        horizontalLayoutWidget_7 = new QWidget(centralwidget);
        horizontalLayoutWidget_7->setObjectName("horizontalLayoutWidget_7");
        horizontalLayoutWidget_7->setGeometry(QRect(860, 490, 160, 80));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1207, 21));
        menuProject = new QMenu(menuBar);
        menuProject->setObjectName("menuProject");
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName("menuTool");
        menuRecord = new QMenu(menuBar);
        menuRecord->setObjectName("menuRecord");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        menuView = new QMenu(menuBar);
        menuView->setObjectName("menuView");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuProject->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuRecord->menuAction());
        menuBar->addAction(menuHelp->menuAction());

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = FeatureTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Property", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = FeatureTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));

        const bool __sortingEnabled = FeatureTable->isSortingEnabled();
        FeatureTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem2 = FeatureTable->item(0, 0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = FeatureTable->item(0, 1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = FeatureTable->item(1, 0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = FeatureTable->item(1, 1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = FeatureTable->item(2, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Sharpness", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = FeatureTable->item(2, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = FeatureTable->item(3, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "HIstogram Equalization", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = FeatureTable->item(3, 1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = FeatureTable->item(4, 0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Noise Reduction", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = FeatureTable->item(4, 1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = FeatureTable->item(5, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Gamma Correction", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = FeatureTable->item(5, 1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = FeatureTable->item(6, 0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Exposure Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = FeatureTable->item(6, 1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = FeatureTable->item(7, 0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Gain", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = FeatureTable->item(7, 1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = FeatureTable->item(8, 0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Dynamic Range", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = FeatureTable->item(8, 1);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = FeatureTable->item(9, 0);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Signal-to-Noise Ratio", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = FeatureTable->item(9, 1);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        FeatureTable->setSortingEnabled(__sortingEnabled);

        label_5->setText(QCoreApplication::translate("MainWindow", "Region of Interest", nullptr));
        frameTemNoise->setText(QCoreApplication::translate("MainWindow", "Frames for temporal noise", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = analysisTable->horizontalHeaderItem(0);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = analysisTable->horizontalHeaderItem(1);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "Frame", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = analysisTable->horizontalHeaderItem(2);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "Temporal", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = analysisTable->horizontalHeaderItem(3);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Total", nullptr));

        const bool __sortingEnabled1 = analysisTable->isSortingEnabled();
        analysisTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem26 = analysisTable->item(0, 0);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = analysisTable->item(1, 0);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = analysisTable->item(2, 0);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "Average", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = analysisTable->item(3, 0);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "Pixel Noise", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = analysisTable->item(4, 0);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "Row Noise", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = analysisTable->item(5, 0);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "Column Noise", nullptr));
        analysisTable->setSortingEnabled(__sortingEnabled1);

        grabButton->setText(QCoreApplication::translate("MainWindow", "Grab Coordinates", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = coordinatesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "y1", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = coordinatesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "y2", nullptr));

        const bool __sortingEnabled2 = coordinatesTable->isSortingEnabled();
        coordinatesTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem34 = coordinatesTable->item(0, 0);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "- -", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = coordinatesTable->item(0, 1);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "- -", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = coordinatesTable->item(1, 0);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "- -", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = coordinatesTable->item(1, 1);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "- -", nullptr));
        coordinatesTable->setSortingEnabled(__sortingEnabled2);

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
        startButton->setText(QString());
        playPauseButton->setText(QString());
        shootButton->setText(QString());
        recordButton->setText(QString());
        zoomInButton->setText(QString());
        zoomOutButton->setText(QString());
        menuProject->setTitle(QCoreApplication::translate("MainWindow", "Project", nullptr));
        menuTool->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuRecord->setTitle(QCoreApplication::translate("MainWindow", "Record", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
