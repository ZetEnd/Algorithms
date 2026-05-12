#include <iostream>
#include <unordered_set>
#include <set>
#include <sstream>
#include <string>

int main(){
std::string line;
std::getline(std::cin, line);

std::istringstream iss(line);
std::set<int> unique_numbers;

int num;
while (iss >> num) {
    unique_numbers.insert(num);
}

std::cout << unique_numbers.size() << std::endl;
    
}