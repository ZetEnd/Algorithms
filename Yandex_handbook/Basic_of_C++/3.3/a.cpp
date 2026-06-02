#include <vector>
#include <iostream>

template <typename T>
void Duplicate(std::vector<T>& v) {

    size_t val = v.size();
    v.resize(val*2);

    auto iter = v.begin() + val;
    auto it = v.begin();
    for (; iter != v.end(); ++iter) {
        *iter = *it;
        ++it;
    }
}

int main(){

    std::vector<int> v{1,2,3};

    Duplicate(v);

    for(int x : v)
       std::cout << x << "\n";
}