#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int n,num;
    unordered_map<int,pair<int,int>> hash;

    cin >> n;

    for(int i = 0; i < n; ++i){
        
        cin >> num;
        if(hash[num].first == 0)
            hash[num].second = i;
        ++hash[num].first;
    }

    vector<pair<int,pair<int,int>>> v;

    for( const auto& [k,val]: hash){
        v.push_back({k,val});
    }

    sort(v.begin(), v.end(),[](const auto& a, const auto& b){
        return tie(a.second.first, b.second.second) > tie(b.second.first, a.second.second);
    });

    for(const auto& x: v){
        for(int i = 0; i < x.second.first;++i)
            cout << x.first << " ";
    }
}