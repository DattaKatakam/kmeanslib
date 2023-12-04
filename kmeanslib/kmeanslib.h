#ifndef KMEANSLIB_H
#define KMEANSLIB_H
#include <iostream>
#include <cmath>
#include <QVector>
#include <algorithm>
#include<string>
#include<unordered_map>

#include "kmeanslib_global.h"

class KMEANSLIB_EXPORT Kmeanslib
{
public:

    // Constructor: Initializes K-means clustering with centroid points, dimensions, and initial data.
    Kmeanslib(const QVector<QVector<double>>& centroidPoints, int dim,const  QVector<QVector<double>>& points);

    // cluster centers.
    QVector<QVector<double>> centroids;

    // Fits points into the coordinate system and updates cluster centers.
    void fit(QVector<QVector<double>>& points);

    // Predicts the cluster to which a given input point belongs.
    std::string predict(const QVector<double>& new_point);

    // Adds a new point to the cluster of previously added points and updates cluster centers.
    void addNewPoint(QVector<double>& point);

private:
    // Initial data points.
    QVector<QVector<double>> basePoints;

    // Dimensions of the data space.
    int dimensions;

    // Updated centroid points of clusters.
    QVector<QVector<QVector<double>>> updatedCentroidPoints;

    // Fitted points and utility functions for clustering.
    QVector<QVector<double>> getUpdatedCentroid(QVector<std::unordered_map<int, QVector<double>>>& fittedPoints);
    QVector<std::unordered_map<int, QVector<double>>> fittedPoints;
    double euclideanDistance(const QVector<double>& p, const QVector<double>& q) const;
    bool getDiffTolerance(const QVector<QVector<double>>& vec1, const QVector<QVector<double>>& vec2);

    // Utility functions for sorting.
    void swap(std::vector<double>& a, std::vector<double>& b);
    int partition(std::vector<std::vector<double>>& arr, int low, int high);
    void quickSort(std::vector<std::vector<double>>& arr, int low, int high);

};

#endif // KMEANSLIB_H
