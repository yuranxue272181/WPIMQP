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
    void setExposureTimeValue(int value);
    void setGainValue(int value);
    void setDynamicRangeValue(int value);
    void setSTNRValue(int value);
    void setTrackingEnabled();
    void onSelectionCompleted(const QPointF &start, const QPointF &end);
    void updateAnalysis(std::shared_ptr<QVector<int>> grayValues, int selectedWidth, int selectedHeight);
    void minCheck();
    void maxCheck();
    void avegCheck();
    void pixelCheck();
    void rowCheck();
    void columnCheck();
    void refreshTotalMean();

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


    //ui
    QToolButton *startBtn;
    QToolButton *playPauseBtn;
    QToolButton *shootBtn;
    QToolButton *recordBtn;
    QToolButton *zoomInBtn;
    QToolButton *zoomOutBtn;
    QPushButton *resetBtn;
    QPushButton *grabBtn;

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
    QSlider *exposureTimeSlider;
    QSlider *gainSlider;
    QSlider *dynamicRangeSlider;
    QSlider *STNRSlider;

    QLabel *brightnessValue;
    QLabel *contrastValue;
    QLabel *sharpnessValue;
    QLabel *HEValue;
    QLabel *NRValue;
    QLabel *GammaValue;
    QLabel *exposureTimeValue;
    QLabel *gainValue;
    QLabel *dynamicRangeValue;
    QLabel *STNRValue;

    QTableWidget *featuresTable;
    QTableWidget *coordTable;
    QTableWidget *analysisTable;

    QCheckBox *minChecker;
    QCheckBox *maxChecker;
    QCheckBox *averageChecker;
    QCheckBox *rowChecker;
    QCheckBox *columnChecker;
    QCheckBox *pixelChecker;


signals:
    // void glInitialized();


};
#endif // MAINWINDOW_H
