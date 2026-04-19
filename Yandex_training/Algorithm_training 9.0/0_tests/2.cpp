#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    // prefix[i] = sum(a[0..i-1]), prefix[0] = 0
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i];

    // last_break: last j where sum(a[0..j-1]) <= a[j]
    int last_break = 0;
    for (int j = 1; j < n; j++)
        if (prefix[j] <= a[j])
            last_break = j;

    // first index where a[i] > a[0] (binary search)
    int first_can_start = (int)(upper_bound(a.begin(), a.end(), a[0]) - a.begin());

    int first_winner = max(last_break, first_can_start);

    for (int i = 0; i < n; i++)
        cout << (i >= first_winner ? 1 : 0) << " \n"[i == n - 1];

    return 0;
}