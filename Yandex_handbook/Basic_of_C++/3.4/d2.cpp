#include <string>
#include <iostream>


bool NextToken(std::string_view& sv, const char delimiter,std::string_view& token){

    if(sv.empty()) return false;

    size_t pos = sv.find(delimiter);

    if(pos == std::string_view::npos){
        token = sv;
        sv = "";
    } else {
        token = sv.substr(0,pos);
        sv.remove_prefix(pos+1);
    }

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