#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){

    string word;
    set<char> s1,s2;

    cin >> word;

    for(char c: word)
        s1.insert(c);

    while(cin >> word){
        for(char c: word){
            if(s1.count(c))
                s2.insert(c);
        }

        s1 = s2;
        s2.clear();

    }

    for(char c: s1)
        cout << c;
}