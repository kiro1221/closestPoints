#include "/Users/kiroragai/Desktop/Projects/C++/closestPoints/bruteforce.cpp"
#include "/Users/kiroragai/Desktop/Projects/C++/closestPoints/divideconquer.cpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;
int main()
{
    BruteForce bf;
    DivideConquer dc;
    int n = 50;
    // std::pair<int, int> points[10] = {
    //     {2, 3},   // Point 1
    //     {12, 30}, // Point 2
    //     {40, 50}, // Point 3
    //     {5, 1},   // Point 4
    //     {12, 10}, // Point 5
    //     {3, 4},   // Point 6
    //     {7, 8},   // Point 7
    //     {6, 15},  // Point 8
    //     {15, 7},  // Point 9
    //     {30, 40}  // Point 10
    // };
    // int length = sizeof(points) / sizeof(points[0]);
    auto start = high_resolution_clock::now();

    //std::vector<std::pair<int, int>> pointsBf = bf.generateRandomPoints(n);
    std::vector<std::pair<int, int>> pointsDc = dc.generateRandomPoints(n);

    std::cout << "Generated Points:\n";
    for (int i = 0; i < pointsDc.size(); i++)
    {
        //std::cout << "Point " << i + 1 << ": (" << pointsBf[i].first << ", " << pointsBf[i].second << ")\n";
        std::cout << "Point " << i + 1 << ": (" << pointsDc[i].first << ", " << pointsDc[i].second << ")\n";
    }
    //bf.bruteForce(pointsBf);
    dc.divideConquer(pointsDc); 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double seconds = duration.count() / 1e6; // Convert microseconds to seconds

    cout << "Time taken by function: " << seconds << " seconds" << endl;
    return 0;
}