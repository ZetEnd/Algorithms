#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){

    int n,r,num;

    cin >> n >> r;

    long long all_var = ((1+(n-1))*(n-1))/2;
    long long count = 0;

    vector<long long> v;

    for(int i = 0; i < n; i++){

        cin >> num;

        v.push_back(num);
    }

    int j = 0;

    for(int i = 0; i < n; i++)
    {
        while(j < n && v[j] - v[i] <= r)
            j++;

        count += (j-1) - i;
    }

    //cout << count;

    cout << all_var - count;
}