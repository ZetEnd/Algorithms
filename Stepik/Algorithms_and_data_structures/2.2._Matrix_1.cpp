#include <iostream>
#include <sstream>
#include <string>

int main() {
    // put your code here
    int N;
    std::cin >> N >> std::ws;
    
    int count = 0;
    for (int i = 0; i < N; i++){
        std::string str;
        std::getline(std::cin, str);
        std::istringstream stream(str);
        
        int x;
        while(stream >> x)
            if (x == 1) count ++;
    }
    
    std::cout << count/2;
    return 0;
}