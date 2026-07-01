#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<long long> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    if(n == 2){
        cout << "1\n" << v[0] << "\n1\n" << v[1];
        return 0;
    }

    int flag = 0;

    vector<long long> first_log;
    vector<long long> second_log;

    vector<pair<int,int>> variants = {
        {0,1},
        {0,2},
        {1,2}
    };

    for(int j = 0; j < 3 && !flag; ++j){

        first_log = {};
        second_log = {};

        int a = variants[j].first;
        int b = variants[j].second;
        long long k1 = v[b] - v[a];

        vector<int> used(n,0);
        first_log.push_back(v[a]);
        first_log.push_back(v[b]);

        used[a] = 1;
        used[b] = 1;

        long long last1 = v[b];

        for(int i = b + 1; i < n; ++i){
            if(v[i] - last1 == k1){
                first_log.push_back(v[i]);
                used[i] = 1;
                last1 = v[i];
            }
        }

        for(int i = 0; i < n; ++i)
            if(!used[i])
                second_log.push_back(v[i]);

        if(second_log.empty())
            continue;

        if(second_log.size() == 1){
            flag = 1;
            break;
        }

        long long k2 = second_log[1] - second_log[0];

        bool ok = true;

        for(size_t i = 1; i < second_log.size(); ++i){
            if(second_log[i] != second_log[i - 1] + k2){
                ok = false;
                break;
            }
        }

        if(ok)
            flag = 1;
    }

    if(!flag){
        cout << -1;
        return 0;
    }

    cout << first_log.size() << "\n";
    for(auto x : first_log)
        cout << x << " ";

    cout << "\n";

    cout << second_log.size() << "\n";
    for(auto x : second_log)
        cout << x << " ";
}