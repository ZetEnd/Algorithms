#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int m;

    size_t n;

    cin >> m >> n;

    map<string, int> table;
    string word, ngrum;

    for(int i = 0; i < m; ++i){


        cin >> word;
        ngrum = "";

        if(word.size() < n) continue;
        
        for(size_t i = 0; i < n; i++){
            ngrum += word[i];
        }

        ++table[ngrum];
        
        for(size_t i = 1; i <= word.size()-n; i++){
            ngrum.erase(ngrum.begin());
            //cout << " = " << ngrum;
            ngrum += word[i+n-1];
            ++table[ngrum];
        }

    }
    vector<pair<string, int>> v(table.begin(), table.end());

    sort(v.begin(), v.end(), [](auto& a, auto& b){
        return tie(a.second, b.first) > tie(b.second, a.first);
    });

    for(const auto& x:v)
        cout << x.first << " - " << x.second << endl;

}