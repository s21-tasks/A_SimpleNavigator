#pragma once

#include "../helpers.h"

namespace s21 {

template<class T>
class BnB {

    public:
        BnB(const Matrix<T> &graph) : graph_(graph), size_(graph.GetCols()) {}

        TsmResult Solve();
    
    private:
        const Matrix<T> &graph_;
        int size_;

        void BnBSearch(int currentVertex, double currentDistance, std::vector<int>& route, TsmResult& bestResult);
        void UpdateBestResult(const std::vector<int>& route, double currentDistance, TsmResult& bestResult);
        double LowerBound(const std::vector<int>& route, int currentVertex);
        void SwapVertices(std::vector<int>& route, int index1, int index2);
};


template<class T>
TsmResult BnB<T>::Solve() {

    std::vector<int> route(size_ + 1);  // route including returning to the starting vertex

    std::iota(route.begin(), route.end(), 0);  // Initialize route with vertices in order
    route.back() = 0;

    TsmResult bestResult;
    bestResult.distance = std::numeric_limits<double>::infinity();

    // Start the branch and bound search
    BnBSearch(0, 0.0, route, bestResult);
    // std::cout << '\n';
    return bestResult;
}

template<class T>
void BnB<T>::BnBSearch(int currentVertex, double currentDistance, std::vector<int>& route, TsmResult& bestResult) {
    if (currentVertex == size_ - 2) {
        UpdateBestResult(route, currentDistance, bestResult);
        return;
    }

    for (int nextVertex = currentVertex + 1; nextVertex < size_; ++nextVertex) {
        if (currentDistance + LowerBound(route, currentVertex) >= bestResult.distance ||
            graph_(route[currentVertex], route[nextVertex]) == 0) {
            continue;
        }

        // Update current route and distance
        // SwapVertices(route, currentVertex + 1, nextVertex);
        std::swap(route[currentVertex + 1], route[nextVertex]);
        double edgeWeight = graph_(route[currentVertex], route[currentVertex + 1]);
        double newDistance = currentDistance + edgeWeight;

        // Recursive call to explore the next vertex
        BnBSearch(currentVertex + 1, newDistance, route, bestResult);

        // Restore the current route and distance
        // SwapVertices(route, currentVertex + 1, nextVertex);
        std::swap(route[currentVertex + 1], route[nextVertex]);
    }
}

template<class T>
void BnB<T>::UpdateBestResult(const std::vector<int>& route, double currentDistance, TsmResult& bestResult) {
    int last = graph_(route[size_ - 1], route[size_]);
    int plast = graph_(route[size_ - 2], route[size_ - 1]);

    if (last != 0 && plast != 0 && (currentDistance += last + plast) < bestResult.distance) {
        bestResult.distance = currentDistance;
        bestResult.vertices = route;
    }
}

template<class T>
double BnB<T>::LowerBound(const std::vector<int>& route, int currentVertex) {
    double lowerBound = 0.0;

    // Calculate the sum of the two minimum edge weights for each unvisited vertex
    for (int i = 1; i < size_; ++i) {
        if (std::find(route.begin(), route.end(), i) == route.end()) {
            double minWeight1 = std::numeric_limits<double>::infinity();
            double minWeight2 = std::numeric_limits<double>::infinity();

            for (int j = 0; j < size_; ++j) {
                if (i != j && std::find(route.begin(), route.end(), j) == route.end()) {
                    double weight = graph_(i, j) == 0 ? std::numeric_limits<double>::infinity() : (double)graph_(i, j);
                    if (weight < minWeight1) {
                        minWeight2 = minWeight1;
                        minWeight1 = weight;
                    } else if (weight < minWeight2) {
                        minWeight2 = weight;
                    }
                }
            }

            lowerBound += minWeight1 + minWeight2;
        }
    }

    return lowerBound;
}

template<class T>
void BnB<T>::SwapVertices(std::vector<int>& route, int index1, int index2) {
    int temp = route[index1];
    route[index1] = route[index2];
    route[index2] = temp;
}

} // namespace s21