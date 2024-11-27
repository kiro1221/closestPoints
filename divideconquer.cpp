#include <iostream>
#include <utility>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <vector>
class DivideConquer
{
public:
    std::vector<std::pair<int, int>> generateRandomPoints(int n)
    {
        std::srand(std::time(0));
        std::vector<std::pair<int, int>> points;

        for (int i = 0; i < n; i++)
        {
            int x = std::rand() % 20001 - 10000; 
            int y = std::rand() % 20001 - 10000;
            points.push_back({x, y});
        }
        return points;
    }
    void divideConquer(const std::vector<std::pair<int, int>> &points)
    {
        float smallestDistance = std::numeric_limits<float>::max(); 
        std::pair<int, int> closestPair[2];
        int length = points.size();

        
        



        std::cout << "Smallest Distance: " << smallestDistance << std::endl;
        std::cout << "Closest Points: (" << closestPair[0].first << ", " << closestPair[0].second << ") and ("
                  << closestPair[1].first << ", " << closestPair[1].second << ")" << std::endl;
    }
};