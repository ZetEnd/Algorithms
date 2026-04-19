#include <iostream>
#include <vector>

int main() {
    
    int N;
    std::cin >> N;
    
    //int numbers[N];
    std::vector <int> vec;
    int x;
    
    for(int i = 0; i < N; i++){
     //std::cin >> numbers[i];
     std::cin >> x;
        
     if(x % 10 == 3) vec.push_back(x);
    }
    
    int min = vec[0];
    for(int num : vec)
        if (num < min) min = num;
    std::cout << min << std::endl;
    // put your code here
    return 0;
}