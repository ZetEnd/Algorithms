#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n;

    cin >> n;

    vector<pair<long long, long long>> v(n);

    for(int i=0;i<n;i++)
        cin >> v[i].first >> v[i].second;

    long long maxl;
    int from, to;

    cin >> maxl >> from >> to;

    from--;
    to--;

    vector<int> dist(n,-1);

    queue<int> q;

    q.push(from);
    dist[from] = 0;

    while(!q.empty()){

        int cur = q.front();
        q.pop();

        for(int nxt = 0; nxt < n; nxt++){

            if(dist[nxt] != -1) continue;

            long long d = abs((v[nxt].first - v[cur].first)) + abs((v[nxt].second - v[cur].second));

            if(d <= maxl){
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
    }

    cout << dist[to];
}