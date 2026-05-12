#include <iostream>
#include <map>
#include <string>

int main() {

    int n, m;

    std::cin >> n >> m;

    std::string w, s;
    std::cin >> w >> s;

    std::map<char, int> char_w;

    std::map<char, int> char_s;

    for(int i = 0; i < n; i++){
        char_w[w[i]] +=1;

        char_s[s[i]] +=1;
    }

    int count = 0;
    if(char_w == char_s) count++;


    for(int i = 1; i < m-n+1; i++){

        char_s[s[i-1]] -=1;
        if(char_s[s[i-1]] == 0) 
            char_s.erase(s[i-1]);

        char_s[s[i+n-1]] +=1;

        if(char_w == char_s) 
            count++;
    }

    std::cout << count << std::endl;

}