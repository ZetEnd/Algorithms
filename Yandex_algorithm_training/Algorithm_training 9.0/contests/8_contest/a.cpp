#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main(){

    map<pair<long long, long long>, int> s;

    string prog;
    cin >> prog;

    long long x=0, y=0, count=0;;

    s[{x,y}] = 1;

    for(char c: prog){

        if(c == 'U') y++;
        if(c == 'D') y--;
        if(c == 'R') x++;
        if(c == 'L') x--;

        s[{x,y}] +=1;

        if(s[{x,y}] == 2)
            count++;
    }

    cout << count;


}