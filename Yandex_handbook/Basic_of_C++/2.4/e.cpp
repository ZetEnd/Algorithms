#include <iostream>
#include <string>

using namespace std;

int main(){

    string s;

    getline(cin, s);

    int l = 0, r = s.size()-1;

    while(l<r){

        while(l < r && s[l] == ' ')
            l++;
        while(l < r && s[r] == ' ')
            r--;
        
        if(s[l] != s[r])
            break; 
        l++;
        r--;
    }

    if(l<r)
        cout << "NO";
    else 
        cout << "YES";
}