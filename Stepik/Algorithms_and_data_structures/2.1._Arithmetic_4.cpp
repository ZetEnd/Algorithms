#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

int main() {
    
    std::string str;
    std::getline(std::cin,str);
    std::istringstream stream(str);
    
    int x;
    std::vector<int> vec;
    while(stream >> x)
       vec.push_back(x);
        
    float min = vec[0];
    float max = vec[0];
    for(int v:vec)
        if (v < min) {min = v;}
        else if (v > max) max = v;
    // put your code here
    
    int res = min/max  * 100;
    //float res = 245%695;
    
    std::cout << res;
    
    return 0;
}