#include <iostream>
#include <unordered_set>

int main(){
std::unordered_set<int> unique_numbers;

int num;

while (std::cin >> num) {
    if(unique_numbers.find(num) != unique_numbers.end())
        std::cout << "YES" << std::endl;
    else{
        std::cout << "NO" << std::endl;
        unique_numbers.insert(num);
    }

    if(std::cin.peek() == '\n') break;
}
   
}