#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

template <typename T>
void PrintResults(T first, T last) {
    for (auto it = first; it != last; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Process(const std::vector<T>& data) {
    std::vector<T> filtered;

    std::copy_if(
        data.begin(),
        data.end(),
        std::back_inserter(filtered),  // ✅ правильно
        [](const T& x) { return x > 0; }
    );

    PrintResults(filtered.begin(), filtered.end());
}

int main() {
    std::vector<int> data = {-3, 5, -1, 7, 0, -2, 10};
    Process(data);  // Вывод: 5 7 10
    
    return 0;
}