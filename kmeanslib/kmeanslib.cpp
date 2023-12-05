#include "kmeanslib.h"

Kmeanslib::Kmeanslib(const QVector<QVector<double>>& centroidPoints, int dim, const QVector<QVector<double>>& points)
    : centroids(centroidPoints), dimensions(dim), basePoints(points) {}


void Kmeanslib::fit(QVector<QVector<double> > &points){
    this->fittedPoints.clear();
    QVector<QVector<double>> centNew;

    do{
        centNew.clear();
        for(const auto& p: this->centroids) centNew.push_back(p);

        this->updatedCentroidPoints.clear();

        for(const auto& p: points){
            QVector<double> centroidDist;

            for(const auto& centroidP: centNew){
                centroidDist.push_back(this->euclideanDistance(p,centroidP));
            }

            double minVal = INT_MAX, minInd;

            for(int i =0; i<centroidDist.size(); i++){
                if(minVal > centroidDist.at(i)){
                    minVal = centroidDist.at(i);
                    minInd = i;
                }
            }

            this->fittedPoints.append({{minInd, p}});
        }
        QVector<QVector<double>> updPoi = this->getUpdatedCentroid(this->fittedPoints);
        this->centroids.clear();
        for(const auto& p1: updPoi) this->centroids.push_back(p1);
    }while(!this->getDiffTolerance(centNew, this->centroids));
}

bool Kmeanslib::getDiffTolerance(const QVector<QVector<double> > &vec1, const QVector<QVector<double> > &vec2){
    double tolerance = 1.000;
    for (int i = 0; i < vec1.size(); ++i) {
        double diff = this->euclideanDistance(vec1[i], vec2[i]);
        if (diff > tolerance) {
            return false;
        }
    }
    return true;
}

QVector<QVector<double>> Kmeanslib::getUpdatedCentroid(QVector<std::unordered_map<int, QVector<double> > > &fittedPoints){
    int sizeCentroid = this->centroids.size();
    QVector<QVector<double>> cp[sizeCentroid];
    QVector<QVector<double>> nCent;
    for(int i = 0; i<sizeCentroid; i++){
        cp[i] = QVector<QVector<double>>();
    }
    for(const auto& p: fittedPoints){
        for (const auto& pair : p) {
            int key = pair.first;
            const QVector<double>& values = pair.second;
            cp[key].push_back(values);
        }
    }
    for(int i = 0; i< sizeCentroid; i++){
        QVector<double> centroidNew(this->dimensions, 0.0);
        if(cp[i].empty()){
            nCent.push_back(this->centroids.at(i));
            continue;
        }
        for(auto& p: cp[i]){
            for(int j=0; j<this->dimensions; j++){
                centroidNew[j] += p.at(j);
            }
        }
        for(int k =0; k<this->dimensions; k++){
            centroidNew[k] /= cp[i].size();
        }
        nCent.push_back(centroidNew);
    }
    return nCent;

}


double Kmeanslib::euclideanDistance(const QVector<double>& p, const QVector<double>& q) const {
    double distance = 0.0;
    for (int i = 0; i < p.size(); ++i) {
        distance += std::pow(p[i] - q[i], 2);
    }
    return std::sqrt(distance);
}

std::string Kmeanslib::predict(const QVector<double>& new_point) {
    std::vector<std::vector<double>> distances;
    for(int i =0; i< this->centroids.size(); i++){
        double distance = this->euclideanDistance(centroids.at(i), new_point);
        std::vector<double> inst;
        inst.push_back(distance);
        inst.push_back(i);
        distances.push_back(inst);
    }
    this->quickSort(distances, 0, distances.size() - 1);

    return std::to_string(static_cast<int>(distances[0][1]));
}

void Kmeanslib::addNewPoint(QVector<double> &point){
    this->basePoints.push_back(point);
    fit(this->basePoints);
}

void Kmeanslib::swap(std::vector<double>& a, std::vector<double>& b) {
    std::vector<double> temp = a;
    a = b;
    b = temp;
}

int Kmeanslib::partition(std::vector<std::vector<double>>& arr, int low, int high) {
    std::vector<double> pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j][0] <= pivot[0]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Kmeanslib::quickSort(std::vector<std::vector<double>>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
