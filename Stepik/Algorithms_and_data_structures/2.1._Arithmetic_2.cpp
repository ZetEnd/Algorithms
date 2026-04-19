#include <iostream>
#include <cmath>

int main() {
    // put your code here
    int N;
    int count = 0;
    std::cin >> N;
    
    for (int i = 1; i <= sqrt(N); i++){
    if (N % i == 0) count ++;
    //if (N / i == i) count++;
    }
    
    std::cout << count;
    return 0;
}