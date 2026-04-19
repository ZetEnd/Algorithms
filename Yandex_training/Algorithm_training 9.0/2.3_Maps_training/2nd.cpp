#include <iostream>
#include <map>
#include <string>

int main(){

    std::map<std::string, std::map<std::string, int>> sales;

    std::string word1, word2;
    int number;

    while(std::cin >> word1 >> word2 >> number){
        sales[word1][word2] += number;

        /*if(std::cin.peek() == '\n') 
        break;*/
    }

    for(auto& name: sales){

        std::cout << name.first << ":" << std::endl;

        for( auto& product: name.second){
            
            std::cout << product.first << " "
                << product.second << std::endl;
        }
    }

    return 0;
}