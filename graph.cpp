#include "graph.h"
#include <QVBoxLayout>

GraphDialog::GraphDialog(QWidget *parent) : QDialog(parent)
{
    // QLineSeries
    QLineSeries *series = new QLineSeries();
    series->append(0, 0);
    series->append(1, 2);
    series->append(2, 4);
    series->append(3, 6);
    series->append(4, 8); // 形成线性关系

    // QChart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Test Chart");
    chart->createDefaultAxes();  // auto create axes
    //QChartView
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    //set layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    setLayout(layout);

    //set size
    setWindowTitle("Test Chart");
    resize(400, 300);
}

GraphDialog::~GraphDialog()
{
}
