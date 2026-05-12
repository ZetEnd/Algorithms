#include <iostream>
#include <set>

int main(){

    int n;
    std::cin >> n;

    int a, b;
    int count = 0;

    std::set<std::pair<int, int>> turtle;

    for(size_t i = 0; i < n; i++){

        std::cin >> a >> b;

        //if(a == n-i-1 && b == i)
        if(a + b == n-1 && turtle.find({a,b}) == turtle.end() && a >= 0 && b >= 0)
            turtle.insert({a,b});
    }

    std::cout << turtle.size();

    return 0;
}