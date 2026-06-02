#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    string line;
    set<string> hash;
    while(cin >> line){
        string way;
        char ch;
        for(char c : line){
            way += c;
            ch = c;
            if(c == '/') hash.insert(way);
        }
        if(ch == '/') hash.erase(way);
    }
    for(const string& s:hash)
        cout << s << endl;
}