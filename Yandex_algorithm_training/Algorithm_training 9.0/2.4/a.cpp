#include <iostream>
#include <map>

int main(){


    int n;
    std::cin >> n;
    std::map<char, int> palyndrom;
    std::string word;
    std::cin >> word;

    for(size_t i = 0; i < n; i++){
        palyndrom[word[i]] += 1;
        
    }

    std::string result;

    int i = 0;
    int max = -1;

    std::string last_char;

    for (auto& pairs: palyndrom){

        if(pairs.second % 2 == 1 && last_char.empty()){
            last_char = std::string(1,pairs.first);
        }

        for(size_t j = 0; j < pairs.second / 2; j++){
            result.insert(i, std::string(1,pairs.first));
            i++;
        }
        for(size_t j = 0; j < pairs.second / 2; j++){
            result.insert(i, std::string(1,pairs.first));
        }



        //std::cout << pairs.first << " " << pairs.second << std::endl;
    }



    result.insert(i, last_char);

    std::cout << result;
    return 0;
}