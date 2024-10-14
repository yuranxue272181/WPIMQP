#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QPushButton>
#include <QToolButton>
<<<<<<< HEAD
#include <QWidget>
=======
#include <QDockWidget>

>>>>>>> d94f1ab4bcbd0a3ebaa74b4cfa5c3a5d49c22438

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
<<<<<<< HEAD
=======
    void pauseVideo();
    void onVideoFinished();
    void zoomIn();
    void zoomOut();
    void recordingStatu();
>>>>>>> d94f1ab4bcbd0a3ebaa74b4cfa5c3a5d49c22438

private:
    Ui::MainWindow *ui;
    GLVideoWidget *gl;

    //ui
    QToolButton *startBtn;
    QToolButton *playPauseBtn;
    QToolButton *shootBtn;
    QToolButton *recordBtn;
    QToolButton *zoomInBtn;
    QToolButton *zoomOutBtn;

    QWidget *mainWidget;
<<<<<<< HEAD
=======
    QWidget *videoWdt;
    QDockWidget *leftDk;
    QDockWidget *rightDk;

signals:
    // void glInitialized();





>>>>>>> d94f1ab4bcbd0a3ebaa74b4cfa5c3a5d49c22438
};
#endif // MAINWINDOW_H
