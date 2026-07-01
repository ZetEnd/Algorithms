#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int n,m;
    int a, b;

    cin >> n >> m;

    vector<pair<int,int>> v;

    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        v.push_back({min(a,b), 1});
        v.push_back({a+b-min(a,b)+1, -1});
    }

    sort(v.begin(), v.end());

    vector<pair<int,int>> points;
    for(int i = 0; i < m; ++i){
        cin >> a;
        points.push_back({a, i});
    }

    sort(points.begin(),points.end());

    int score = 0;
    int v_idx = 0;

    vector<int> ans(m);

    for(auto [x, idx] : points){

        while(v_idx < v.size() && v[v_idx].first <= x){
            score += v[v_idx].second;
            v_idx++;
        }
        ans[idx] = score;
    }

    for(int x:ans){
        cout << x << " ";
    }

	return 0;
}
