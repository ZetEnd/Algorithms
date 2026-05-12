#include <iostream>

using namespace std;

int main(){

    string s;

    cin >> s;

    string res;
    res += s[0];

    for(int i = 1; i != s.size(); i++){

        char c = s[i];
        switch(c){

            case 'b':
            case 'f':
            case 'p':
            case 'v':
                if(res[res.size()-1] != '1')
                    res += '1';
                break;
            case 'c':
            case 'g':
            case 'j':
            case 'k':
            case 'q':
            case 's':
            case 'x':
            case 'z':
                if(res[res.size()-1] != '2')
                        res += '2';
                break;
            case 'd':
            case 't':
                if(res[res.size()-1] != '3')
                    res += '3';
                break;
            case 'l':
                if(res.back() != '4')
                    res += '4';
                break;
            case 'm':
            case 'n':
                if(res.back() != '5')
                    res += '5';
                break;
            case 'r':
                if(res.back() != '5')
                    res += '5';
                break;
        }

    }

    while(res.size() < 4){
        res += '0';
    }

    if(res.size() > 4){
        res = res.substr(0,4);
    }

    cout << res;
}