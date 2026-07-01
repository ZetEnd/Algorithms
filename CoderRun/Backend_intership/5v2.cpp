#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() 
{
	int n,m;
    int a, b;

    cin >> n >> m;

    map<int, int> table;

    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        table[min(a,b)] += 1;
        table[a+b-min(a,b)+1] -=1;
    }


    vector<pair<int,int>> points;
    for(int i = 0; i < m; ++i){
        cin >> a;
        points.push_back({a,i});
    }

    sort(points.begin(), points.end());
    vector<int> ans(m);
    int score = 0;

    auto it = table.begin();
    for(auto [x, idx]: points){
        while( it != table.end() && it->first <= x){
            score += it->second;
            ++it;
        }
        ans[idx] = score;
    }

    for(int x:ans){
        cout << x << " ";
    }

	return 0;
}
