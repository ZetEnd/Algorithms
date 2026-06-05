#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    string word;
    unordered_map<string, int> mp;

    size_t n;

    cin >> n;

    while(cin >> word)
        ++mp[word];

    /*for(const auto& [k,v] : mp)
        cout << k << " - " << v << endl;*/

    vector<pair<string,int>> v{mp.begin(), mp.end()};

    sort(v.begin(),v.end(),[](const auto& p1, const auto& p2){
        return tie(p1.second,p2.first) > tie(p2.second, p1.first);
    });

    for(size_t i = 0; i != v.size(); ++i){
        if(i == n) break;
        cout << v[i].first << "\t" << v[i].second << endl;
    }
}