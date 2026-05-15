#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Split(const std::string& str, char delimiter){

    std::vector<std::string> res;

    if(str.empty()){
        res.push_back("");
        return res;
    }

    size_t prev_ind = 0;

    for(size_t i = 0; i < str.size(); i++){
        
        if( str[i] == delimiter){
            res.push_back(str.substr(prev_ind,i - prev_ind));
            prev_ind = i + 1;
        }

    }

    if(prev_ind < str.size())
        res.push_back(str.substr(prev_ind));
    else
        res.push_back("");

    return res;
}

int main(){

    std::vector<std::string> res = Split("What_is_your_name_", '_');
    
    for(size_t i = 0; i < res.size(); i++){

        std::cout << res[i] << std::endl;
    }
}