#include <iostream>
using namespace std;

int main() {
    long long n;
    long long ans = 1e18;
    long long k = 1;

    cin >> n;

    while (k <= n) {
        long long x = (n + k - 1) / k; 

        long long R;
        if (x == 1) {
            R = n;
        } else {
            R = n / (x - 1);
        }

        
        long long kk = k;
        long long xx = (n + kk - 1) / kk;
        long long t = kk * xx - n;

        if (abs(kk - 2 * t) <= 1) {
            ans = min(ans, abs(kk - xx));
        }
    
        long long kk1 = R;
        long long xx1 = (n + kk1 - 1) / kk1;
        long long t1 = kk1 * xx1 - n;

        if (abs(kk1 - 2 * t1) <= 1) {
            ans = min(ans, abs(kk1 - xx1));
        }
        

        k = R + 1;
    }

    cout << ans << endl;
}