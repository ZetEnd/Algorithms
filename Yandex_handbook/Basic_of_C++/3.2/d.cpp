#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(){

    int n;

    cin >> n;

    map<int, set<string>> book;

    for(int i = 0; i < n ;i++){
        int num;
        string word;

        cin >> word >> num;

        book[num].insert(word);
    }

    for(const auto& [k,v] : book){
        cout << k;
        for(const auto& s: v)
            cout << " " << s;
        cout << endl;
    }
}