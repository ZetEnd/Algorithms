#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;


pair<int ,int> right_f1(int n, int k, vector<int> v){

    map<int, int> source;

    for(int i = 0; i < n; i++){

        source[v[i]]++;
    }


    map<int, int> m;

    int j = 0;

    while(m.size() != source.size()){
            m[v[j]]++;
            j++;
        }

    int minv = j;
    int imin = 1, jmin = j;

    //cout << minv;

    for(int i = 0; i < n; i++){
        m[v[i]]--;
        //m[v[j]]++;

        if(m[v[i]] == 0)
            m.erase(v[i]);

        //cout << i << " " << j  << " " << m[v[i]] << endl;
        /*for(auto x: m){
            cout << "1 i =" << i << " j= " << j << " 1st = " << x.first << " 2nd = " << x.second << endl;
        }*/

        while(j < n && m.size() != source.size()){
            m[v[j]]++;
            j++;
        }

        if (m.size() != source.size())
            break;

        if(j-(i+1) < minv){
            minv = j-(i+1);
            jmin = j;
            imin = i+2;
        }

        /*for(auto x: m){
            cout << "1 i =" << i << " j= " << j << " 1st = " << x.first << " 2nd = " << x.second << " min =" << minv << endl;
        }*/

    }

    return  {imin, jmin};
}

pair<int ,int> bad_f2(int n, int k, vector<int> v){

    map<int, int> source;

    for(int i = 0; i < n; i++){

        source[v[i]]++;
    }

    map<int, int> m = source;

    int i = 0, j = n-1;

    while(i < n){

        m[v[i]]--;
        if(m[v[i]] != 0) i++;
        else {
            m[v[i]]++;
            break;
        }
    }
    
    while(j>i){

        m[v[j]]--;
        if(m[v[j]] != 0) j--;
        else {
            m[v[j]]++;
            break;
        }
    }

    int i1 = i+1, j1 = j+1;

    int min1,min2;

    min1 = abs(j-i);

    m = source;
    i = 0;
    j = n-1;

    while(j>0){

        m[v[j]]--;
        if(m[v[j]] != 0) j--;
        else {
            m[v[j]]++;
            break;
        }
    }

    while(i < j){

        m[v[i]]--;
        if(m[v[i]] != 0) i++;
        else {
            m[v[i]]++;
            break;
        }
    }

    min2 = abs(j-i);
    //cout << i << " s " << j << endl;

    //cout << min1 << "  d " << min2 << endl;

    if(min1 < min2)
        return {i1, j1};
    else
        return {i+1, j+1};

}

int main(){

    int n,k;

    //cin >> n >> k;

    vector<int> v(n);
    map<int, int> source;

    int count = 0;

    for(int i = 1; i < 100; i++){

        n = i;
        vector<int> v(n);

        for(int o = 0; o < 1000; o++){
        for(int j = 0; j < n; j++){

            v[j]++;
            if (right_f1(n,k,v) != bad_f2(n,k,v))
                count ++;
        }
        }
    }

    cout << count;

}