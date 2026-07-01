#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> hw(n);
    for(int i = 0; i < n; i++) 
        cin >> hw[i];
    
    vector<int> scores(m+1);

    for(int i = 0; i <= m; i++) 
        cin >> scores[i];
    
    const long long minim = -1e18;
    vector<long long> dp(k+1, minim);
    dp[0] = 0;
    

    long long val;
    for(int i = 0; i < n; i++){
        vector<long long> ndp(k+1, minim);

        for(int j = 0; j <= k; j++){

            if(dp[j] == minim) 
                continue;
            
            int maxim = min(k - j, m - hw[i]);

            for(int l = 0; l <= maxim; l++){
                val = dp[j] + scores[hw[i] + l];
                ndp[j + l] = max(ndp[j + l], val);
            }
        }
        dp = ndp;
    }
    
    cout << dp[k];
}