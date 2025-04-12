#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QDockWidget>
#include <QSlider>
#include <QLabel>
#include <QTableWidget>
#include <QCheckBox>
#include <QSpinBox>
#include <QQueue>
#include <QComboBox>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class GLVideoWidget;
class Analysis;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setFrameRateFromBoard(int value);


private slots:
    void renderVideo();
    void pauseVideo();
    void onVideoFinished();
    void zoomIn();
    void zoomOut();
    void recordingStatu();
    void setBrightness(int value);
    void setContrast(int value);
    void setSharpness(int value);
    void setHEValue(int value);
    void setNRValue(int value);
    void setGammaValue(int value);
    void reset();
    void setTrackingEnabled();
    void onSelectionCompleted(const QPointF &start, const QPointF &end);
    void updateAnalysis(std::shared_ptr<QVector<int>> grayValues, int selectedWidth, int selectedHeight);
    void minCheck();
    void maxCheck();
    void avegCheck();
    void pixelCheck();
    void rowCheck();
    void columnCheck();
    void resetTotal();
    void updateQueueSize(int value);
    void grabBtnChecked();

    void setButtonIconColor(QToolButton *button, const QString &iconPath, const QColor &color);
    //***control component***future work***
    //void setFrameRate(int value);

private:
    QByteArray testData;
    Ui::MainWindow *ui;
    GLVideoWidget *gl;
    Analysis *analysis;
    std::shared_ptr<QVector<int>> selectedRegion;
    float zoomFactor;
    int selectedH;
    int selectedW;
    int totalMin;
    int totalMax;
    float totalMeanSum;
    int totalMeanCounter;
    float totalPixelSum;
    int totalPixelCounter;
    float totalRowSum;
    int totalRowCounter;
    float totalColumnSum;
    int totalColumnCounter;
    QQueue<int> minQ;
    QQueue<int> maxQ;
    QQueue<float> avegQ;
    QQueue<float> rowQ;
    QQueue<float> colQ;
    QQueue<float> pixQ;
    int queueSize;
    int frameRate;
    QMenu* menuProject;
    QMenu* menuTool;
    QMenu* menuView;
    QMenu* menuEdit;
    QMenu* menuRecord;
    QMenu* menuHelp;
    QAction *recordingAction;
    QAction *screenshootAction;
    QAction *grabCoAction;



    //ui
    QToolButton *startBtn;
    QToolButton *playPauseBtn;
    QToolButton *shootBtn;
    QToolButton *recordBtn;
    QToolButton *zoomInBtn;
    QToolButton *zoomOutBtn;
    QPushButton *resetBtn;
    QPushButton *grabBtn;
    //testgraph
    QPushButton *openGraphButton;

    QSpinBox *spin;

    QWidget *mainWidget;
    QWidget *videoWdt;
    QDockWidget *leftDk;
    QDockWidget *rightDk;

    QSlider *brightnessSlider;
    QSlider *contrastSlider;
    QSlider *sharpnessSlider;
    QSlider *HESlider;
    QSlider *NRSlider;
    QSlider *GammaSlider;


    QLabel *brightnessValue;
    QLabel *contrastValue;
    QLabel *sharpnessValue;
    QLabel *HEValue;
    QLabel *NRValue;
    QLabel *GammaValue;
    QLabel*frameTemNoise;

    QTableWidget *featuresTable;
    QTableWidget *coordTable;
    QTableWidget *analysisTable;

    QCheckBox *minChecker;
    QCheckBox *maxChecker;
    QCheckBox *averageChecker;
    QCheckBox *rowChecker;
    QCheckBox *columnChecker;
    QCheckBox *pixelChecker;

    QHBoxLayout *layout;
    /*control component***future work***
    QSlider *exposureTimeSlider;
    QSlider *gainSlider;
    QSlider *dynamicRangeSlider;
    QSlider *STNRSlider;
    QLabel *exposureTimeValue;
    QLabel *gainValue;
    QLabel *dynamicRangeValue;
    QLabel *STNRValue;
    QComboBox *frameRateCB;
    void openGraphDialog();
    void setExposureTimeValue(int value);
    void setGainValue(int value);
    void setDynamicRangeValue(int value);
    void setSTNRValue(int value);*/

signals:
    // void glInitialized();


};
#endif // MAINWINDOW_H
