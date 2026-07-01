#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){

    int n,m,k,num;

    cin >> n >> m >> k;

    vector<int> hw(n);

    vector<int> scores(m+1);
    long long res = 0;

    for(int i = 0; i < n; ++i){
        cin >> hw[i];
    }

    for(int i = 0; i < m+1; ++i)
        cin >> scores[i];
    multiset<pair<int,int>> mset;


    for(int i = 0 ; i < n; i++){
        res += scores[hw[i]];
        if(hw[i] < m)
            mset.insert({scores[hw[i] + 1] - scores[hw[i]], hw[i] + 1});
    }

    for(int i = 0; i < k; ++i){
        if(!mset.empty()){
            auto it = --mset.end();
            int score = it->first;
            int task = it->second;
            mset.erase(it);

            res += score;

            if(task < m)
                mset.insert({scores[task+1] - scores[task], task+1});
        }
    }

    cout << res;
}