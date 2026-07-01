#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;




int main(){

    int n, num;

    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    if(v.size() == 2){
        cout << "1\n" << v[0] << "\n1\n" << v[1];
    } else {

        int flag = 1;

        sort(v.begin(), v.end());

        vector<int> k {v[1]-v[0], v[2]-v[0], v[2] - v[1]};
        vector<int> second_log;

        for(int j = 0; j < 3; j++){
            flag = 1;
            second_log = {};

            if(j != 2){
                int last_member = v[0];

                for(size_t i = 1; i < v.size();++i){
                if(v[i] - last_member == k[j])
                    last_member = v[i];
                else 
                    second_log.push_back(v[i]);
            }


            } else {
                int last_member = v[1];
                second_log.push_back(v[0]);

                for(size_t i = 2; i < v.size();++i){
                if(v[i] - last_member == k[j])
                    last_member = v[i];
                else 
                    second_log.push_back(v[i]);
                }
            }


            if(second_log.size() == 1) break;

            int second_k = second_log[1] - second_log[0];

            for(size_t i = 1; i < second_log.size(); ++i)
                if(second_log[i] != second_log[i-1]+second_k){
                    flag = 0;
                    break;
                }
            

            if(flag) break;
        }

        if(flag){

            cout << second_log.size() << endl;
            for(int x : second_log)
                cout << x << " ";


            cout << "\n" << v.size()-second_log.size() << endl;
            size_t i_second = 0;
            for(size_t i = 0; i < v.size(); ++i){
                if(i_second < second_log.size() && v[i] == second_log[i_second])
                    ++i_second;
                else
                    cout << v[i] << " ";
            }
        }
        else {
            cout << -1;
        }

    }

}