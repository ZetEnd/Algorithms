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
        cout << "1\n" << v[0] << "\n";
        cout << "1\n" << v[1] << "\n";
        return 0;
    }

    vector<pair<int,int>> start = {
        {0,1},
        {0,2},
        {1,2}
    };

    int flag = 0;

    vector<long long> first_log;
    vector<long long> second_log;

    for(int j = 0; j < 3 && !flag; ++j){

        first_log.clear();
        second_log.clear();

        int a = start[j].first;
        int b = start[j].second;

        long long d1 = v[b] - v[a];
        long long last1 = v[b];

        first_log.push_back(v[a]);
        first_log.push_back(v[b]);

        long long d2 = -1;
        long long last2 = -1;

        bool ok = true;

        for(int i = 0; i < n; ++i){

            if(i == a || i == b)
                continue;

            long long x = v[i];

            bool can1 = (x - last1 == d1);

            bool can2 = true;

            if(second_log.empty())
                can2 = true;
            else if(second_log.size() == 1)
                can2 = true;
            else
                can2 = (x - last2 == d2);

            if(can1){

                first_log.push_back(x);
                last1 = x;

            }
            else if(can2){

                second_log.push_back(x);

                if(second_log.size() == 2)
                    d2 = second_log[1] - second_log[0];

                last2 = x;

            }
            else{

                ok = false;
                break;
            }
        }

        if(ok && !first_log.empty() && !second_log.empty())
            flag = 1;
    }

    if(!flag){
        cout << -1;
        return 0;
    }

    cout << first_log.size() << "\n";
    for(long long x : first_log)
        cout << x << " ";

    cout << "\n";

    cout << second_log.size() << "\n";
    for(long long x : second_log)
        cout << x << " ";

    return 0;
}