#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <limits>
#include <chrono> // For measuring time
using namespace std::chrono;
struct Point {
    int x, y;
};
// Function to calculate the Euclidean distance between two points
double calculate_distance(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void find_closest_pair(const std::vector<Point> &points) {
    double min_distance = std::numeric_limits<double>::max();
    Point closest_pair[2];

    for (size_t i = 0; i < points.size() - 1; ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double distance = calculate_distance(points[i], points[j]);
            if (distance < min_distance) {
                min_distance = distance;
                closest_pair[0] = points[i];
                closest_pair[1] = points[j];
            }
        }
    }
    std::cout << "Closest pair: (" << closest_pair[0].x << ", " << closest_pair[0].y
              << ") and (" << closest_pair[1].x << ", " << closest_pair[1].y << ")" << std::endl;
    std::cout << "Distance: " << min_distance << std::endl;
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
    find_closest_pair(points);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    std::cout << "Time taken by brute force solution: " << duration.count() << " ms" << std::endl;
    return 0;
}
