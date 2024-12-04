#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

void generate_points(int n, const std::string &filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < n; ++i) {
        int x = (rand() % 20001) - 10000; 
        int y = (rand() % 20001) - 10000;
        file << x << " " << y << std::endl;
    }

    file.close();
    std::cout << "Generated " << n << " points into " << filename << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number_of_points>" << std::endl;
        return 1;
    }
    int n = std::stoi(argv[1]);
    if (n <= 0) {
        std::cerr << "Number of points must be greater than 0." << std::endl;
        return 1;
    }
    std::string filename = "output" + std::to_string(n) + ".txt";
    generate_points(n, filename);
    return 0;
}
