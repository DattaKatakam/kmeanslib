Overview
The Kmeanslib header file encapsulates the functionality for the K-means clustering algorithm in C++. It provides a class with methods and attributes to initialize, fit, and predict clusters based on multidimensional input data.

Methods

    Public Methods
        Constructor (Kmeanslib):

            Initializes the K-means clustering algorithm with specified centroid points, dimensions, and initial data.
        
        fit Method:

            Fits the provided points into the coordinate system.
            Updates the cluster centers by adding new points.

        predict Method:

            Determines the cluster to which a given input point belongs.
            
        addNewPoint Method:

            Adds a new point to the cluster of previously added points.
            Updates the centers of each cluster.

    Private Methods
        getUpdatedCentroid:

        Retrieves the updated centroid points of clusters.
        euclideanDistance Method:

        Calculates the Euclidean distance between two points.
        getDiffTolerance Method:

        Iterates until the new centroids are stabilized, i.e., not changed significantly.

    Utility Functions
        swap Method:

            Swaps two vectors.
        
        partition Method:

            Partitions a vector for use in the quicksort algorithm.
        
        quickSort Method:

            Implements the quicksort algorithm to sort vectors.
    
    Dependencies
        <iostream>
        <cmath>
        <QVector>
        <algorithm>
        <string>
        <unordered_map>

Usage
    Include this header file in your project to utilize the K-means clustering functionality provided by the Kmeanslib class.