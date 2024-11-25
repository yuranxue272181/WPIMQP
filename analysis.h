#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QVector>
#include <memory>

class Analysis
{
public:
    Analysis();
    ~Analysis();

    float meanCal(std::shared_ptr<QVector<int>> grayValues);
    float pixelNoiseCal(std::shared_ptr<QVector<int>> grayValues, float mean);
    float calculateRowNoise(std::shared_ptr<QVector<int>> grayValues, int rowIndex, int selectedWidth);
    float calculateAllRowNoise(std::shared_ptr<QVector<int>> grayValues, int selectedHeight, int selectedWidth);
    float calculateColumnNoise(std::shared_ptr<QVector<int>> grayValues, int columnIndex, int selectedHeight, int selectedWidth);
    float calculateAllColumnNoise(std::shared_ptr<QVector<int>> grayValues, int selectedHeight, int selectedWidth);
};

#endif // ANALYSIS_H
