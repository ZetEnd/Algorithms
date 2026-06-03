#include <iostream>
#include <vector>
#include <algorithm>

template <typename Iter>
Iter Unique(Iter first, Iter last){

    if(first == last) return last;

    auto it = first;
    ++first;
    while(first != last){
        if(*it != *first){
            ++it;
            *it = std::move(*first);
        }
        ++first;
    }

    return ++it;
}

int main(){

    std::vector<int> v{0,0,1,2,2,2,3,3,3,4,5,6,6};
    //v.erase(Unique(v.begin(), v.end()), v.end());

    auto it = Unique(v.begin(), v.end());

    std::cout << *it << '\n';

    for(int x:v)
        std::cout << x << " ";

}