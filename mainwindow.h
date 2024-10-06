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

private:
    Ui::MainWindow *ui;
    GLVideoWidget *gl;

    //ui
    QToolButton *playBtn;
    QWidget *mainWidget;
    QDockWidget *leftDk;
    QDockWidget *rightDk;




};
#endif // MAINWINDOW_H
