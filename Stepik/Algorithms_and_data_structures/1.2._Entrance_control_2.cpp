#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    // put your code here
    
    std::string str;
    std::getline(std::cin, str);
    std::istringstream stream(str);
    
    std::vector <int> vec;
    int x;
    
    while (stream >> x)
        vec.push_back(x);
    
    for(int x: vec){
    if (x % 2 == 0) {
    std::cout << x << std::endl;
    break;
    }
    }
    
    return 0;
}