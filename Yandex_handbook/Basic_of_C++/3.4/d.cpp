#include <string>
#include <iostream>


bool NextToken(std::string_view& sv, const char delimiter,std::string_view& token){

    if(sv.empty()) return false;

    for(size_t i = 0; i < sv.size(); ++i){
        if(sv[i] == delimiter){
            token = sv.substr(0,i);
            sv.remove_prefix(i+1);
            return true;
        }
    }

    token = sv;
    sv = "";

    return true;
}

int main() {
    std::string_view sv = "Hello world and good bye";

    const char delimiter = ' ';
    std::string_view token;

    // Делим строку на токены по разделителю и перебираем эти токены:
    while (NextToken(sv, delimiter, token)) {
        // обрабатываем очередной token
        // например, печатаем его на экране:
        std::cout << token << "\n";
    }
}