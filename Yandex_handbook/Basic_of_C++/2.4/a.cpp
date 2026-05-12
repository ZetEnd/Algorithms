#include <iostream>

using namespace std;

int main(){

    string s;

    cin >> s;

    int flag = 1;

    int flag_1 = 0, flag_2 = 0, flag_3 = 0, flag_4 = 0;

    if(s.size() < 8 || s.size() > 14)
        flag = 0;
    
    for(char c : s){

        if( c < 33 || c > 126){
            flag = 0;
            break;
        }

        if(c >= 'a' && c <= 'z')
            flag_1 = 1;
        else
        if(c >= 'A' && c <= 'Z')
            flag_2 = 1;
        else
        if(c >= '0' && c <= '9')
            flag_3 = 1;
        else    
            flag_4 = 1;

    }

    if(flag_1+flag_2+flag_3+flag_4 < 3)
        flag = 0;


    if(flag)
        cout << "YES";
    else 
        cout << "NO";
}