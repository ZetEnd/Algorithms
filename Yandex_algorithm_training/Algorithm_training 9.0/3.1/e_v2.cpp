#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<long long> v{0};

    long long sum1 = 0, sum2 = 0, sum3 = 0;
    int num;

    for(int i = 1; i <= n; i++){

        cin >> num;

        v.push_back(v[i-1] + num);
        sum1 = (sum1 + num) % 1000000007;

        sum2 = (sum2 + sum1*num) % 1000000007;

        sum3 = (sum3 + sum2*num) % 1000000007;
    }

    cout << sum3  % 1000000007;

}