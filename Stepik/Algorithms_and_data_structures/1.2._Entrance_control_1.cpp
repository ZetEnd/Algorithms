#include <iostream>

int main() {
    // put your code here
    
    int temp;
    std::cin >> temp;
    
    if (temp < -25) std::cout << "жутко холодно" << std::endl;
    if (temp > -26 && temp < 0) std::cout << "холодно" << std::endl;
    if (temp > -1 && temp < 10) std::cout << "прохладно" << std::endl;
    if (temp > 9 && temp < 25) std::cout << "тепло" << std::endl;
    if (temp > 24) std::cout << "жара" << std::endl;
    
    return 0;
}