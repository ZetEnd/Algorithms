#include <iostream>
#include <set>
#include <sstream>
#include <string>

int main(){
    
    std::string line1, line2;

    std::getline(std::cin, line1);
    std::getline(std::cin, line2);

    std::set<int> set1;
    std::istringstream iss1(line1);
    int num;

    while(iss1 >> num) {
        set1.insert(num);
    }

    std::set<int> set2;
    std::istringstream iss2(line2);
    while(iss2 >> num){
        set2.insert(num);
    }

    for(int x : set1){
        if (set2.find(x) != set2.end())
            std::cout << x << " ";
    }

    return 0;
}