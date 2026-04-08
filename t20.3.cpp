#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

struct Point {
    int x;
    int y;
};


struct Segment {
    Point p1;
    Point p2;
    double length;
};

double calculateDistance(const Point& a, const Point& b) {
    return std::hypot(a.x - b.x, a.y - b.y);
}

int main() {
    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file." << std::endl;
        return 1;
    }

    std::vector<Point> points;
    char ch;
    int x, y;

    while (inputFile >> ch) {
        if (ch == '(') {
            inputFile >> x >> ch; // зчитуємо X і кому ','
            if (ch == ',') {
                inputFile >> y >> ch; // зчитуємо Y і дужку ')'
                if (ch == ')') {
                    points.push_back({x, y});
                }
            }
        }
    }

    inputFile.close();

    if (points.size() < 2) {
        std::cerr << "Not enough points to form a segment." << std::endl;
        return 0;
    }

    std::vector<Segment> segments;

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double len = calculateDistance(points[i], points[j]);
            segments.push_back({points[i], points[j], len});
        }
    }

    std::sort(segments.begin(), segments.end(), [](const Segment& a, const Segment& b) {
        return a.length < b.length;
    });

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file." << std::endl;
        return 1;
    }

    outputFile << "Sorted Segments (by length):\n";
    outputFile << "----------------------------\n";

    for (const auto& seg : segments) {
        outputFile << "Segment [(" << seg.p1.x << ", " << seg.p1.y << ") - ("
                   << seg.p2.x << ", " << seg.p2.y << ")] "
                   << "Length: " << std::fixed << std::setprecision(2) << seg.length << "\n";
    }

    outputFile.close();
    std::cout << "Done! Results written to " << outputFileName << std::endl;

    return 0;
}