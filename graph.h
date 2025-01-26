#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>


class GraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraphDialog(QWidget *parent = nullptr);
    ~GraphDialog();

private:
    QChartView *chartView;
};

#endif // GRAPH_H
