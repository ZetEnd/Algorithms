#include <iostream>

int main() {
    // put your code here
    int N;
    std::cin >> N;
    
    int sum = 0;
    
    if (N > 0){
    for(int i = 1; i <= N; i++){
    sum += i;
    }
    }
    else if (N <= 0)
    {
     for(int i = N; i <= 1; i++){
    sum += i;
    }   
    }
    
    std::cout << sum;
    return 0;
}