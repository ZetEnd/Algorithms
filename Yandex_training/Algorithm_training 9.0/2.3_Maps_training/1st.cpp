#include <iostream>
#include <map>
#include <string>

int main(){

    std::map<std::string, std::string> pairs;

    int n;

    std::cin >> n;

    for(int i = 0; i < n; i++){

        std::string word1, word2;

        std::cin >> word1 >> word2;

        pairs[word1] = word2;
        pairs[word2] = word1;
    }

    std::string target;

    std::cin >> target;

    std::cout << pairs[target];
}