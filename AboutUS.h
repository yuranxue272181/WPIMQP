#ifndef ABOUTUS_H
#define ABOUTUS_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QPainter>
#include <QPen>
#include <QBrush>

class AboutUS : public QDialog
{
    Q_OBJECT

public:
    explicit AboutUS(QWidget *parent = nullptr);
    ~AboutUS();

};

#endif // ABOUTUS_H
