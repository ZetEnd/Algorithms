#include <vector>
#include <iostream>

template <typename T>
void Duplicate(std::vector<T>& v) {

    std::vector<T> copy = v;

    v.insert(v.end(),copy.begin(), copy.end());
}

int main(){

    std::vector<int> v{1,2,3};

    Duplicate(v);

    for(int x : v)
       std::cout << x << "\n";
}