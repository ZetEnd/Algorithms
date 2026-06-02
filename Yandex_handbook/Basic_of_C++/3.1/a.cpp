#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <string>

using namespace std;

template <typename Container>
void Print(const Container& container, string s){
    
    int first = 1;
    for(const auto& elem: container){
        if(!first)
            cout << s;

        cout << elem;
        first = 0;
    }
        cout << "\n";
}

int main() {
    std::vector<int> data = {1, 2, 3, 4};
    Print(data, ", ");  // 1, 2, 3, 4
}