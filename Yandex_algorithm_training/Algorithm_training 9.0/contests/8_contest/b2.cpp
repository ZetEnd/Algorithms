#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Special rule from problem
    int cases;
    cin >> cases;
    if (cases < 0) {
        cout << -2 << "\n";
        return 0;
    }

    while (cases--) {
        long long n, d;
        cin >> n >> d;

        vector<long long> t(n), k(n);
        for (int i = 0; i < n; i++) cin >> t[i] >> k[i];

        // prefix sum of k: wait[i] = k[0] + ... + k[i-1]
        vector<long long> slack(n);
        long long wait = 0;
        for (int i = 0; i < n; i++) {
            slack[i] = t[i] - wait;
            wait += k[i];
        }

        // suffix minimum of slack
        vector<long long> suf_min(n + 1, LLONG_MAX);
        for (int i = n - 1; i >= 0; i--)
            suf_min[i] = min(slack[i], suf_min[i + 1]);

        // Binary search: find leftmost pos where suf_min[pos] >= d
        // If suf_min[0] >= d -> pos=0 -> answer=1
        // If suf_min[n-1] < d -> pos=n -> answer=n+1
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (suf_min[mid] >= d)
                hi = mid;
            else
                lo = mid + 1;
        }
        cout << lo + 1 << "\n";
    }
    return 0;
}