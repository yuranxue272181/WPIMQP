#include "AboutUS.h"

AboutUS::AboutUS(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle("About Us");

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Hello, we are a team from WPI. Feel free to contact us for further information.");
    label->setAlignment(Qt::AlignCenter);
    label->setWordWrap(true);
    layout->addWidget(label);

        QLabel *imageLabel = new QLabel(this);
    QPixmap pixmap(":/icons/WPI.png");
    imageLabel->setPixmap(pixmap.scaled(150, 75, Qt::KeepAspectRatio));  // 控制图片大小

    QHBoxLayout *imageLayout = new QHBoxLayout();
    imageLayout->addStretch(1);
    imageLayout->addWidget(imageLabel);

    layout->addLayout(imageLayout);

    setFixedSize(400, 200);
}

AboutUS::~AboutUS()
{

}
