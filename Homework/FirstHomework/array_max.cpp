#include <iostream>
#include <vector>
#include <algorithm>

int getMax(const std::vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {3, 7, 2, 9, 10, 5},
        {-10, -5, -3},
        {100, 200, 300, 50, 400},
        {0, 0, -2, 0},
        {10000}
    };

    for (const auto& arr : testCases) {
        std::cout << getMax(arr) << std::endl;
    }

    return 0;
}
