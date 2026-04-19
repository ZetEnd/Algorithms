#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


int main() {

    string s;
    cin >> s;

    int n = s.size();

    unordered_map<string_view, pair<int,int>> mp;

    auto func = [&](int mid) -> int {
        mp = {};
        mp.reserve(n);
        for (int i = 0; i + mid <= n; i++) {
            string_view sub(s.data() + i, mid);
            auto& [last, cnt] = mp[sub];
            if (cnt == 0) {
                last = i;
                cnt = 1;
            } else if (i >= last + mid) {
                last = i;
                cnt++;
            }
        }
        int best = 0;
        for (auto& [key, val] : mp) best = max(best, val.second);
        return best;
    };

    int k = func(1);

    int lo = 1, hi = n, ans = 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (func(mid) >= k) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}