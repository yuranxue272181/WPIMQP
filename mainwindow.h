#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QDockWidget>


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
    QDockWidget *leftDk;
    QDockWidget *rightDk;





};
#endif // MAINWINDOW_H
