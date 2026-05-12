#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    int x, y;

    bool flag;
    vector<int> res;

    for(size_t i = 0; i < 4*n; i++){
        cin >> x >> y;

        v.push_back({x,y});

        if((i+1) % 4 == 0 && i != 0){
            auto start = v.begin() + i - 3;

            auto end = start + 4;

            /*cout << v[i-3].first << v[i-2].first << v[i-1].first << v[i].first << " first " << endl;
            cout << v[i-3].second << v[i-2].second << v[i-1].second << v[i].second << " second " << endl;*/

            sort(start, end);

            /*cout << v[i-3].first << v[i-2].first << v[i-1].first << v[i].first << " first " << endl;
            cout << v[i-3].second << v[i-2].second << v[i-1].second << v[i].second << " second " << endl;*/

            flag = true;

            if(v[i-3].first - v[i-2].first != v[i-1].first - v[i].first)
            flag = false;

            if(v[i-3].second - v[i-2].second != v[i-1].second - v[i].second)
            flag = false;

            if(flag) res.push_back(1);
            else res.push_back(0);
        }


    }

    for(int x : res){

        if(x == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}