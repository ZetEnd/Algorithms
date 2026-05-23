#include<iostream>
#include <string>
#include <unordered_map>

using namespace std;

int f(string s, string j){

    if(s.size() != j.size())
        return 0;

    unordered_map<char, int> h1,h2;

    for(char c: s)
        h1[c] += 1;

    for(char c: j)
        h2[c] += 1;

    if(h1 == h2)
        return 1;
    else 
        return 0;
}

int main(){

    string s,j;

    cin >> s >> j;

    cout << f(s,j);

    return 0;
}