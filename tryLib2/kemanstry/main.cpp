#include <QCoreApplication>
#include"../../kmeanslib/kmeanslib.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<QVector<double>> points = {
        {2.0, 3.5},
        {3.0, 2.8},
        {4.2, 2.5},
        {2.7, 4.0},
        {13.5, 12.2},
        {1.7, 18.0},
        {5.4, 19.3},
        {8.5, 16.2},
        {17.9, 15.6},
        {3.7, 3.0},
        {2.4, 14.3},
        {4.5, 23.2},
        {3.9, 12.6},
        {14.5, 13.2},
        {13.9, 12.6}
    };
    QVector<QVector<double>> centPoints = {
        {5.0, 6.0},
        {10.0, 13.5},
        {18, 16.0}
    };
    Kmeanslib kInstance(centPoints, 2, points);
    kInstance.fit(points);
    std::cout<< "centroids of these points are:" << std::endl;
    for(const auto& pnt: kInstance.centroids){
        std::cout<<"{"<<std::endl;
        for(const auto p: pnt){
            std::cout<< p << ",";
        }
        std::cout<<"}"<<std::endl;
    }
    std::cout<<std::endl;
    std::cout << kInstance.predict({6, 18}) << "This is in region"<< std::endl;
    std::cout << kInstance.predict({1, 2}) << "This is in region"<< std::endl;

    QVector<double> pntNew {2, 10};
    kInstance.addNewPoint(pntNew);
    std::cout<< "Updated centroids after adding a point to already existing points" << std::endl;
    for(const auto& pnt: kInstance.centroids){
        std::cout<<"{"<<std::endl;
        for(const auto p: pnt){
            std::cout<< p << ",";
        }
        std::cout<<"}"<<std::endl;
    }
    std::cout<<std::endl;
    std::cout << kInstance.predict({16, 11}) << "This is in region"<< std::endl;


    QVector<QVector<double>> points3D = {
        {2.0, 3.5, 6.8},
        {3.0, 2.8, 5.2},
        {4.2, 2.5, 4.7},
        {2.7, 4.0, 6.3},
        {3.5, 2.2, 5.9},
        {4.0, 3.8, 4.5},
        {2.8, 4.5, 6.1},
        {4.3, 2.9, 5.7},
        {3.2, 3.7, 4.3},
        {2.5, 4.2, 5.8},
        {4.1, 2.4, 6.4},
        {3.7, 3.0, 4.9},
        {2.4, 4.3, 5.5},
        {4.5, 3.2, 4.1},
        {3.9, 2.6, 5.6},
        {15.0, 17.5, 10.8},
        {16.0, 18.8, 11.2},
        {17.2, 15.5, 12.7},
        {16.7, 19.0, 13.3},
        {18.5, 16.2, 14.9}
    };

    QVector<QVector<double>> centroids3D = {
        {5.0, 6.5, 9.8},
        {6.0, 5.8, 8.2},
        {7.2, 5.5, 7.7}
    };

    Kmeanslib try3d(centroids3D, 3, points3D);
    try3d.fit(points3D);

    std::cout<< "centroids of these points are:" << std::endl;
    for(const auto& pnt: try3d.centroids){
        std::cout<<"{"<<std::endl;
        for(const auto p: pnt){
            std::cout<< p << ",";
        }
        std::cout<<"}"<<std::endl;
    }
    std::cout << " This is in region " << try3d.predict({7.2, 16.2, 7.7}) << std::endl;
    std::cout << " This is in region "<< try3d.predict({2, 2, 1}) <<  std::endl;
    return a.exec();
}
