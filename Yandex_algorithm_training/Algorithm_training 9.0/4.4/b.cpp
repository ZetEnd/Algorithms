#include <iostream>
#include <stack>
#include <vector>
#include <climits>

using namespace std;

int main(){

    int n,num;

    stack<pair<int, int>> st;

    vector<int> v;

    int i = 0;

    cin >> n;

    vector<pair<int,int>> res1(n), res2(n);

    while(cin >> num){

        v.push_back(num);

        while(st.size() != 0 && num < st.top().first ){

            res1[st.top().second] = {st.top().first, i};
            st.pop();
        }

        st.push({num, i});

        i++;
    }


    for(int i = 0; i <n; i++){

        //cout << " res1  = " << res1[i].first << " sec = " << res1[i].second << endl;
    }

    while(st.size() != 0){
        res1[st.top().second] = {st.top().first, n};
        st.pop();
    }

    //cout << endl;

    for(int i = 0; i <n; i++){

        //cout << " v2 res1  = " << res1[i].first << " sec = " << res1[i].second << endl;
    }


    stack<pair<int, int>> st_left;

    for(int i = n-1; i >=0; i--){

        while(st_left.size() != 0 && v[i] < st_left.top().first){
            
            res2[st_left.top().second] = {st_left.top().first, i};
            st_left.pop();
        }

        st_left.push({v[i], i});
    }

    while(st_left.size() != 0){
        res2[st_left.top().second] = {st_left.top().first, -1};
        st_left.pop();
    }

    //cout << endl;

    for(int i = 0; i <n; i++){

        //cout << " v2 res2  = " << res2[i].first << " sec = " << res2[i].second << endl;
    }



    long long val, maxval = -1;
    for(int i = 0; i <n; i++){
        val = (long long)res1[i].first * (res1[i].second - res2[i].second -1 );

        //cout << " val = " << val;
        maxval = max(maxval, val);
    }



    cout << maxval;
}