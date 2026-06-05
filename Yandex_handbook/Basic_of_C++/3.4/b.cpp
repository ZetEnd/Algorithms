#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    size_t n,k;

    cin >> n >> k;

    vector<int> v(n);
    vector<int> res;
    multiset<int> mset;

    for(size_t i = 0; i < n; ++i){
        cin >> v[i];
        if(i < k) mset.insert(v[i]);
    }

    res.push_back(*(mset.begin()));

    for(size_t i = k; i < n; ++i){
        mset.insert(v[i]);
        auto it = mset.find(v[i-k]);
        mset.erase(it);
        res.push_back(*(mset.begin()));
    }

    for(int x: res)
        cout << x << endl;

}