#include <iostream>
#include <vector>
#include <string>

std::string CommonPrefix(const std::vector<std::string>& words){

    if(words.empty())
        return "";

    int l = 0, r = words[0].size()+1;

    while(l < r){

        size_t mean = l + (r-l)/2;

        int flag = true;

        for(size_t i = 1; i < words.size(); i++){
            if(mean > words[i].size() || words[0].substr(0, mean) != words[i].substr(0,mean)){
                flag = false;
                break;
            }
        }

        if(flag)
            l = mean + 1;
        else 
            r = mean;
    }

    //std::string res = "";
    //if(l )

    return words[0].substr(0,l-1);
}

int main(){

    std::vector<std::string> v {};

    std::cout << CommonPrefix(v);
}