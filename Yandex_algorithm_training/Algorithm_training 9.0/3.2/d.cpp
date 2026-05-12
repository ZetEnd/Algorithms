#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    long long n,k;

    cin >> n >> k;

    vector<long long> v(n);
    map<long long, long long> source;

    for(int i = 0; i < n; i++){

        cin >> v[i];

        source[v[i]]++;
    }

    map<long long, long long> m = source;

    long long i = 0, j = n-1;

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

    long long i1 = i+1, j1 = j+1;


    long long min1,min2;

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
        cout << i1 << " " << j1;
    else
        cout << i+1 << " " << j+1;

}