#include <iostream>
#include <set>
#include <string>
#include <set>

int main(){

    int n;
    std::cin >> n;

    int m;
    std::string language;

    std::set<std::string> all_language;
    std::set<std::string> intersect_language;
    std::set<std::string> buffer;


    for(size_t i = 0; i < n; i++){
        std::cin >> m;

        for(size_t j = 0; j < m; j++){

            std::cin >> language;
            if(i == 0){
                buffer.insert(language);

            } else
            if(intersect_language.find(language) != intersect_language.end()){
                buffer.insert(language);
            }

            all_language.insert(language);
        }

        intersect_language = buffer;
        buffer = {};

    }

    std::cout << intersect_language.size() << std::endl;

    for(std::string lang : intersect_language){
        std::cout << lang << std::endl;
    }

    std::cout << all_language.size() << std::endl;

    for(std::string lang : all_language){
        std::cout << lang << std::endl;
    }

    return 0;
}