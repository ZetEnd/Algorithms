
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if (n < 0 || m < 0) {
        cout << -2 << "\n";
        return 0;
    }

    vector<tuple<long long, long long, long long>> events(n);

    for (int i = 0; i < n; i++) {
        long long l, r, x;
        cin >> l >> r >> x;
        events[i] = {l, r, x};
    }

    for (int i = 0; i < m; i++) {
        long long q;
        cin >> q;

        long long res = 0;

        for (auto &[l, r, x] : events) {
            if (l <= q && q <= r) {
                if ((q - l) % 2 == 0)
                    res += x;
                else
                    res -= x;
            }
        }

        cout << res << "\n";
    }

    return 0;
}