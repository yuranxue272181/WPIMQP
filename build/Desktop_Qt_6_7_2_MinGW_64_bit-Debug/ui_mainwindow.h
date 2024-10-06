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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *videoWidget;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QTableWidget *tableWidget_2;
    QWidget *tab_5;
    QTextBrowser *textBrowser;
    QSplitter *splitter;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *startButton;
    QToolButton *playPauseButton;
    QToolButton *shootButton;
    QToolButton *recordButton;
    QToolButton *zoomInButton;
    QToolButton *zoomOutButton;
    QMenuBar *menuBar;
    QMenu *menuhe_p;
    QMenu *menuCollection;
    QMenu *menuEdit;
    QMenu *menuRecord;
    QMenu *menuHelp;
    QMenu *menuView;
    QDockWidget *leftDock;
    QWidget *dockWidgetContents_7;
    QTableWidget *tableWidget;
    QDockWidget *rightDock;
    QWidget *dockWidgetContents_8;
    QTabWidget *tabWidget;
    QWidget *tab;
    QToolBox *toolBox;
    QWidget *page;
    QSlider *horizontalSlider;
    QLabel *label;
    QWidget *page_2;
    QSlider *verticalSlider;
    QWidget *Sharpen;
    QScrollBar *verticalScrollBar;
    QWidget *tab_3;
    QToolBox *toolBox_2;
    QWidget *page_5;
    QSlider *horizontalSlider_2;
    QLabel *label_3;
    QWidget *page_6;
    QWidget *Sharpen_2;
    QWidget *tab_2;
    QTextEdit *textEdit;
    QWidget *widget1;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 554);
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
        centralwidget->setSizeIncrement(QSize(10, 10));
        videoWidget = new QWidget(centralwidget);
        videoWidget->setObjectName("videoWidget");
        videoWidget->setGeometry(QRect(12, 41, 352, 288));
        sizePolicy.setHeightForWidth(videoWidget->sizePolicy().hasHeightForWidth());
        videoWidget->setSizePolicy(sizePolicy);
        videoWidget->setMinimumSize(QSize(352, 288));
        videoWidget->setSizeIncrement(QSize(10, 10));
        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(12, 361, 341, 140));
        tabWidget_2->setMinimumSize(QSize(0, 140));
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tableWidget_2 = new QTableWidget(tab_4);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(10, 0, 311, 101));
        tableWidget_2->horizontalHeader()->setVisible(true);
        tableWidget_2->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_2->horizontalHeader()->setHighlightSections(false);
        tableWidget_2->verticalHeader()->setVisible(true);
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        textBrowser = new QTextBrowser(tab_5);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 0, 321, 101));
        textBrowser->setMinimumSize(QSize(321, 101));
        tabWidget_2->addTab(tab_5, QString());
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(12, 335, 96, 16));
        splitter->setOrientation(Qt::Orientation::Horizontal);
        label_5 = new QLabel(splitter);
        label_5->setObjectName("label_5");
        splitter->addWidget(label_5);
        label_6 = new QLabel(splitter);
        label_6->setObjectName("label_6");
        splitter->addWidget(label_6);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(1, 7, 371, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        startButton = new QToolButton(widget);
        startButton->setObjectName("startButton");
        startButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(startButton);

        playPauseButton = new QToolButton(widget);
        playPauseButton->setObjectName("playPauseButton");
        playPauseButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(playPauseButton);

        shootButton = new QToolButton(widget);
        shootButton->setObjectName("shootButton");
        shootButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(shootButton);

        recordButton = new QToolButton(widget);
        recordButton->setObjectName("recordButton");
        recordButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(recordButton);

        zoomInButton = new QToolButton(widget);
        zoomInButton->setObjectName("zoomInButton");
        zoomInButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(zoomInButton);

        zoomOutButton = new QToolButton(widget);
        zoomOutButton->setObjectName("zoomOutButton");
        zoomOutButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(zoomOutButton);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 21));
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
        leftDock = new QDockWidget(MainWindow);
        leftDock->setObjectName("leftDock");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leftDock->sizePolicy().hasHeightForWidth());
        leftDock->setSizePolicy(sizePolicy1);
        leftDock->setMinimumSize(QSize(201, 39));
        leftDock->setMaximumSize(QSize(201, 524287));
        leftDock->setFeatures(QDockWidget::DockWidgetFeature::DockWidgetMovable);
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName("dockWidgetContents_7");
        tableWidget = new QTableWidget(dockWidgetContents_7);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 1, __qtablewidgetitem7);
        QFont font;
        font.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem8->setFont(font);
        tableWidget->setItem(1, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 1, __qtablewidgetitem9);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 0, 201, 481));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        leftDock->setWidget(dockWidgetContents_7);
        MainWindow->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, leftDock);
        rightDock = new QDockWidget(MainWindow);
        rightDock->setObjectName("rightDock");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(rightDock->sizePolicy().hasHeightForWidth());
        rightDock->setSizePolicy(sizePolicy3);
        rightDock->setMinimumSize(QSize(221, 39));
        rightDock->setMaximumSize(QSize(221, 524287));
        rightDock->setFeatures(QDockWidget::DockWidgetFeature::DockWidgetMovable);
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName("dockWidgetContents_8");
        tabWidget = new QTabWidget(dockWidgetContents_8);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 201, 301));
        tabWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName("tab");
        toolBox = new QToolBox(tab);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(10, 10, 181, 251));
        toolBox->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 181, 164));
        horizontalSlider = new QSlider(page);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(0, 20, 121, 22));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 20, 21, 16));
        toolBox->addItem(page, QString::fromUtf8("Brightness"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 181, 164));
        verticalSlider = new QSlider(page_2);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setGeometry(QRect(20, 30, 22, 111));
        verticalSlider->setOrientation(Qt::Orientation::Vertical);
        toolBox->addItem(page_2, QString::fromUtf8("Contrast"));
        Sharpen = new QWidget();
        Sharpen->setObjectName("Sharpen");
        Sharpen->setGeometry(QRect(0, 0, 181, 164));
        verticalScrollBar = new QScrollBar(Sharpen);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setGeometry(QRect(120, 20, 16, 111));
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);
        toolBox->addItem(Sharpen, QString::fromUtf8("Sharpen"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        toolBox_2 = new QToolBox(tab_3);
        toolBox_2->setObjectName("toolBox_2");
        toolBox_2->setGeometry(QRect(12, 24, 191, 181));
        toolBox_2->setStyleSheet(QString::fromUtf8(""));
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        page_5->setGeometry(QRect(0, 0, 191, 94));
        horizontalSlider_2 = new QSlider(page_5);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(0, 20, 121, 22));
        horizontalSlider_2->setOrientation(Qt::Orientation::Horizontal);
        label_3 = new QLabel(page_5);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(130, 20, 21, 16));
        toolBox_2->addItem(page_5, QString::fromUtf8("test"));
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        page_6->setGeometry(QRect(0, 0, 100, 30));
        toolBox_2->addItem(page_6, QString::fromUtf8("test"));
        Sharpen_2 = new QWidget();
        Sharpen_2->setObjectName("Sharpen_2");
        Sharpen_2->setGeometry(QRect(0, 0, 100, 30));
        toolBox_2->addItem(Sharpen_2, QString::fromUtf8("test"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        textEdit = new QTextEdit(tab_2);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(30, 30, 104, 61));
        tabWidget->addTab(tab_2, QString());
        widget1 = new QWidget(dockWidgetContents_8);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(0, 350, 211, 121));
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 10, 51, 20));
        pushButton = new QPushButton(widget1);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 30, 75, 31));
        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(120, 60, 75, 31));
        label_4 = new QLabel(widget1);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 10, 111, 20));
        pushButton_3 = new QPushButton(widget1);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 40, 75, 23));
        pushButton_4 = new QPushButton(widget1);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 60, 75, 23));
        rightDock->setWidget(dockWidgetContents_8);
        MainWindow->addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, rightDock);

        menuBar->addAction(menuhe_p->menuAction());
        menuBar->addAction(menuCollection->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuRecord->menuAction());
        menuBar->addAction(menuHelp->menuAction());

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);
        toolBox_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "No.", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Qx", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Qy", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Grab Coordinates", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Camera 1:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  connecting</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  1000x1000</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-i"
                        "ndent:0; text-indent:0px;\">   etc</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Camera 2:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  disconnecting</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Device Connection", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Time: 60s", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "FPS: 30", nullptr));
        startButton->setText(QString());
        playPauseButton->setText(QString());
        shootButton->setText(QString());
        recordButton->setText(QString());
        zoomInButton->setText(QString());
        zoomOutButton->setText(QString());
        menuhe_p->setTitle(QCoreApplication::translate("MainWindow", "Project", nullptr));
        menuCollection->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuRecord->setTitle(QCoreApplication::translate("MainWindow", "Record", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        leftDock->setWindowTitle(QCoreApplication::translate("MainWindow", "Feature Properties", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Property", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "2", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(1, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(1, 1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        rightDock->setWindowTitle(QCoreApplication::translate("MainWindow", "Image Processing", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        toolBox->setItemText(toolBox->indexOf(Sharpen), QCoreApplication::translate("MainWindow", "Sharpen", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "   Image Enhancement", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(page_5), QCoreApplication::translate("MainWindow", "test", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(page_6), QCoreApplication::translate("MainWindow", "test", nullptr));
        toolBox_2->setItemText(toolBox_2->indexOf(Sharpen_2), QCoreApplication::translate("MainWindow", "test", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Feature2", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Input</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                        "text-indent:0px; font-weight:700;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Feature3 ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Device ", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connnect", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "   Coordinates", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "test", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
