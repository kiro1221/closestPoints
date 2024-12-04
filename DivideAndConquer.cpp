#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>
#include <chrono> // For measuring time
using namespace std::chrono;

struct Point {
    int x, y;
};

// Structure to store the result of closest pair
struct ClosestPairResult {
    double distance;
    Point point1;
    Point point2;
};

// Function to calculate the Euclidean distance between two points
double calculate_distance(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool compare_x(const Point &a, const Point &b) {
    return a.x < b.x;
}

bool compare_y(const Point &a, const Point &b) {
    return a.y < b.y;
}

// Function to find the closest pair in a strip
ClosestPairResult closest_pair_in_strip(std::vector<Point> &strip, double d, ClosestPairResult current_result) {
    std::sort(strip.begin(), strip.end(), compare_y);

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; ++j) {
            double distance = calculate_distance(strip[i], strip[j]);
            if (distance < current_result.distance) {
                current_result.distance = distance;
                current_result.point1 = strip[i];
                current_result.point2 = strip[j];
            }
        }
    }

    return current_result;
}

// Recursive function to find the closest pair
ClosestPairResult closest_pair_rec(std::vector<Point> &points, int left, int right) {
    if (right - left <= 3) {
        ClosestPairResult result = {std::numeric_limits<double>::max(), points[left], points[left]};
        for (int i = left; i < right; ++i) {
            for (int j = i + 1; j < right; ++j) {
                double distance = calculate_distance(points[i], points[j]);
                if (distance < result.distance) {
                    result.distance = distance;
                    result.point1 = points[i];
                    result.point2 = points[j];
                }
            }
        }
        return result;
    }

    int mid = left + (right - left) / 2;
    Point mid_point = points[mid];

    ClosestPairResult left_result = closest_pair_rec(points, left, mid);
    ClosestPairResult right_result = closest_pair_rec(points, mid, right);

    ClosestPairResult best_result = (left_result.distance < right_result.distance) ? left_result : right_result;

    std::vector<Point> strip;
    for (int i = left; i < right; ++i) {
        if (std::abs(points[i].x - mid_point.x) < best_result.distance) {
            strip.push_back(points[i]);
        }
    }

    return closest_pair_in_strip(strip, best_result.distance, best_result);
}

// Wrapper function to find and print the closest pair
ClosestPairResult find_closest_pair(std::vector<Point> &points) {
    std::sort(points.begin(), points.end(), compare_x);
    return closest_pair_rec(points, 0, points.size());
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }

    std::vector<Point> points;
    Point p;
    while (file >> p.x >> p.y) {
        points.push_back(p);
    }
    file.close();

    auto start_time = std::chrono::high_resolution_clock::now();
    ClosestPairResult result = find_closest_pair(points);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    std::cout << "Closest pair: (" << result.point1.x << ", " << result.point1.y << ") and ("
              << result.point2.x << ", " << result.point2.y << ")" << std::endl;
    std::cout << "Distance: " << result.distance << std::endl;
    std::cout << "Time taken by divide-and-conquer solution: " << duration.count() << " ms" << std::endl;

    return 0;
}
