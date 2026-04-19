#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){

    int n,r,num;

    cin >> n >> r;

    long long all_var = (((long long)(n))*(n-1))/2;
    long long count = 0;

    vector<long long> v;

    for(int i = 0; i < n; i++){

        cin >> num;

        v.push_back(num);
    }

    int i = 0, j = 0;

    while(i < n && j < n){

        if(i == j) {
            i++;
            continue;
        }

        //cout << i << " " << j << " " << endl;
        if(abs(v[i]-v[j]) <= r && i!=j){
            count += abs(i - j);
            i++;
            continue;
        }

        if(i>j)
            j++;
        else
            i++;
    }

    //cout << count;

    cout << all_var - count;
}