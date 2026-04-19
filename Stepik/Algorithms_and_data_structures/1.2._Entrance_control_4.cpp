#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int main() {
    
    std::vector<int> vec;
    int val, x, chet = 0, nechet = 0;
    
    std::string str;
    std::getline(std::cin, str);
    std::istringstream stream(str);
    
    while (stream >> x)
        vec.push_back(x);
  
    for (int val:vec){
     if (val % 2 == 0)
     {
         chet++;
     }
        else{
         nechet++;   
        }
        
    }
    //for(int n : vec)
        //std::cout << chet << " " << nechet;
        
    if(chet > nechet)
    {
        std::cout << "even ";
    }
    else if (nechet > chet){
        std::cout << "odd ";
    }
    else std::cout << "equal ";
    // put your code here
    return 0;
}