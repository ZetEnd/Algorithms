#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main(){

    int a,b,c,d;

    cin >> a >> b >> c >> d;

    vector<pair<int, int>> v;

    if(a > 0 && b > 0){
        v.push_back({ max(a,b)+1, 1 });
    }

    if(a > 0 && c > 0){
        v.push_back({ b+1, d+1});
    }

    if(b > 0 && d > 0){
        v.push_back({ a+1, c+1});
    }

    if(c > 0 && d > 0){
        v.push_back({ 1, max(c,d) + 1});
    }

    int min = INT_MAX;
    int res1, res2;

    for (auto& x:v){
        if(x.first + x.second < min){
            min = x.first + x.second;
            res1 = x.first;
            res2 = x.second;
        }
    }

    cout << res1 << " " << res2;
}