#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> arr;
    vector<long long> presum{0};
    int num;

    for(int i = 0; i < n; i++){

        cin >> num;

        arr.push_back(num);

        presum.push_back((presum[i] + num)%1000000007);
    }

    long long sum = 0;
    long long MOD = 1000000007;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){

            //cout << presum[n] - presum[j+1] << " ";
            long long sum_after = (presum[n] - presum[j+1] + MOD) % MOD;
            sum = (sum + (long long)arr[i] * arr[j] % MOD * sum_after) % MOD;


        }
    }

    cout << sum%1000000007;
}