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


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class GLVideoWidget;


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

private:
    QByteArray testData;
    Ui::MainWindow *ui;
    GLVideoWidget *gl;

    //ui
    QToolButton *startBtn;
    QToolButton *playPauseBtn;
    QToolButton *shootBtn;
    QToolButton *recordBtn;
    QToolButton *zoomInBtn;
    QToolButton *zoomOutBtn;
    QPushButton *resetBtn;

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

    QTableWidget *featuresTable;



signals:
    // void glInitialized();





};
#endif // MAINWINDOW_H
