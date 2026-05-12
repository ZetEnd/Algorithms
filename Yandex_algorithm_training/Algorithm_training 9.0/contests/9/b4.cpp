#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int n, k;
    cin >> n >> k;

    vector<long long> ps(n+1, 0);
    for(int i = 0; i < n; i++){
        long long x; cin >> x;
        ps[i+1] = ps[i] + x;
    }

    long long ans = 0;
    for(int l = 0; l <= n; l++)
        for(int r = l+1; r <= n; r++){
            long long s = ps[r] - ps[l];
            if(s % k != 0)
                ans = max(ans, s);
        }

    cout << ans;
}