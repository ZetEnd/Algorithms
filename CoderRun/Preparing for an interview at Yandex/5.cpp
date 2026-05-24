#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    int n;

    cin >> n;

    vector<pair<long long,long long>> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    int from, to;

    long long max_len;

    cin >> max_len >> from >> to;

    vector<vector<long long>> w(n, vector<long long>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            //long cur_len = sqrt((v[i].first - v[j].first)*(v[i].first - v[j].first) + (v[i].second - v[j].second)*(v[i].second - v[j].second));

            long long cur_len = abs((v[i].first - v[j].first)) + abs((v[i].second - v[j].second));

            if(i == j || cur_len > max_len) w[i][j] = -1;
            else w[i][j] = cur_len;
        }
    }

    queue<long> q;
    vector<int> visited(n);
    vector<long> distances(n);
    vector<int> papa(n);

    visited[from-1] = 1;
    distances[from-1] = 0;
    papa[from-1] = -1;

    q.push(from-1);

    while(!q.empty()){

        int g = q.front();
        q.pop();
        for(size_t i = 0; i < w[g].size(); i++){
            if(w[g][i] == -1) continue;
            int cur_len = w[g][i];
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
                distances[i] = distances[g] + 1;
                papa[i] = g;
            }
        }
    }

    if(!visited[to-1])
        cout << -1;
    else{
        vector<int> path;
        for(int now = to-1; now != from-1; now = papa[now])
            path.push_back(now);

        
        path.push_back(from-1);
        reverse(path.begin(), path.end());

        cout << distances[to-1];
        //cout << path.size() << endl;

        int res = 0;

        for(int i = 0; i < path.size()-1; i++){
            //cout << path[i] << " ";
            res += w[i][i+1];
            //cout << w[i][i+1] << " d ";
        }

        //cout << "res = " << res;
    }




}