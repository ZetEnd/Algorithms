#include <iostream>
#include <vector>
#include <string>

int main(){

    int n;
    std::cin >> n;

    std::vector<std::pair<std::string, std::string>> synonyms;

    for(size_t i = 0; i < n; i++){
        std::string w1, w2;
        std::cin >> w1 >> w2;

        synonyms.push_back({w1,w2});
    }

    std::string target;
    std::cin >> target;

    for(auto& pair: synonyms){

        if(pair.first == target)
            std::cout << pair.second << std::endl;
        else 
        if (pair.second == target)
            std::cout << pair.first << std::endl;
    }

    return 0;
}