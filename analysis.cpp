#include "analysis.h"

Analysis::Analysis() {

}
Analysis::~Analysis() {

}


//calculate mean of ROI
float Analysis::meanCal(std::shared_ptr<QVector<int>> grayValues){
    //mean
    float mean = 0.0f;
    for (int value : *grayValues) {
        mean += value;
    }
    mean /= grayValues->size();
    return mean;
}

//calculate standard deviation of ROI
float Analysis::pixelNoiseCal(std::shared_ptr<QVector<int>> grayValues, float mean){
    float variance = 0.0f;
    for (int value : *grayValues) {
        variance += std::pow(value - mean, 2);
    }
    variance /= grayValues->size();
    return std::sqrt(variance);
}

//calculate row noise for one row
float Analysis::calculateRowNoise(std::shared_ptr<QVector<int>> grayValues, int rowIndex, int selectedWidth) {
    float mean = 0.0f;
    int rowStartIndex = rowIndex * selectedWidth;
    int rowEndIndex = rowStartIndex + selectedWidth;

    for (int i = rowStartIndex; i < rowEndIndex; ++i) {
        mean += (*grayValues)[i];
    }
    mean /= selectedWidth;

    float variance = 0.0f;
    for (int i = rowStartIndex; i < rowEndIndex; ++i) {
        variance += std::pow((*grayValues)[i] - mean, 2);
    }
    variance /= selectedWidth;
    return std::sqrt(variance);
}

//calculate all row noise
float Analysis::calculateAllRowNoise(std::shared_ptr<QVector<int>> grayValues, int selectedHeight, int selectedWidth) {
    if(selectedHeight == 1)
        return 0;
    QVector<float> rowNoiseValues;
    float mean = 0.0f;
    for (int row = 0; row < selectedHeight; ++row) {
        float rowNoise = calculateRowNoise(grayValues, row, selectedWidth);
        rowNoiseValues.append(rowNoise);
        mean+=rowNoise;
    }
    mean /= rowNoiseValues.size();
    float rowNoiseVariance = 0.0f;
    for (float noise : rowNoiseValues) {
        rowNoiseVariance += std::pow(noise - mean, 2);
    }
    rowNoiseVariance /= rowNoiseValues.size();
    return std::sqrt(rowNoiseVariance);
}
//calculate column noise of one column
float Analysis::calculateColumnNoise(std::shared_ptr<QVector<int>> grayValues, int columnIndex, int selectedHeight, int selectedWidth){
    float mean = 0.0f;
    for (int row = 0; row < selectedHeight; ++row) {
        mean += (*grayValues)[row * selectedWidth + columnIndex];
    }
    mean /= selectedHeight;
    float variance = 0.0f;
    for (int row = 0; row < selectedHeight; ++row) {
        variance += std::pow((*grayValues)[row * selectedWidth + columnIndex] - mean, 2);
    }
    variance /= selectedHeight;
    return std::sqrt(variance);
}

//calculate all column noise
float Analysis::calculateAllColumnNoise(std::shared_ptr<QVector<int>> grayValues, int selectedHeight, int selectedWidth) {
    if (selectedWidth == 1)
        return 0;
    QVector<float> columnNoiseValues;
    float mean = 0.0f;
    for (int col = 0; col < selectedWidth; ++col) {
        float columnNoise = calculateColumnNoise(grayValues, col, selectedHeight, selectedWidth);
        columnNoiseValues.append(columnNoise);
        mean += columnNoise;
    }
    mean /= columnNoiseValues.size();
    float columnNoiseVariance = 0.0f;
    for (float noise : columnNoiseValues) {
        columnNoiseVariance += std::pow(noise - mean, 2);
    }

    columnNoiseVariance /= columnNoiseValues.size();
    return std::sqrt(columnNoiseVariance);
}
