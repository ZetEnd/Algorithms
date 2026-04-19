#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

int main() {
    
    std::string str;
    std::getline(std::cin, str);
    //std::cout << str << std::endl; 
    
    int x;
    std::vector<int> vec;
    for(const char s :str)
        //std::cout << s - '0' << std::endl; 
        vec.push_back(s - '0');
    
    int chislo = 1;
    std::map<int,int> res;
    
    for(int v:vec){ 
        if (v!= chislo)
        {
            while(v!=chislo){
                //std::cout << v << "fu"<< chislo << std::endl; 
                chislo++;
            }
            //std::cout << chislo << "go" << std::endl;   
            res[chislo] = 1;
        } else{
            res[chislo]++;
        }
    }
        for(const auto& [key,value] : res){
         std::cout << value<<key;   
        }
            
    // put your code here
    return 0;
}