#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int main(){

    int n,k;

    cin >> n >> k;

    vector<int> v(n);
    map<int, int> source;

    for(int i = 0; i < n; i++){

        cin >> v[i];

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

    cout << imin << " " << jmin;



}