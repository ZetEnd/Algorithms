
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<string> g;

const long long MOD = 1000000007, B = 131;

vector<vector<long long>> h;
vector<long long> p, inv;

long long pw(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long get(int r, int l, int len) {
    return (h[r][l + len] - h[r][l] + MOD) % MOD * inv[l] % MOD;
}

int cmp(int r1, int c1, int r2, int c2) {
    for (int i = 0; i < n; i++) {
        if (get(r1 + i, c1, m) != get(r2 + i, c2, m)) {
            int l = 0, r = m;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (get(r1 + i, c1, mid) == get(r2 + i, c2, mid))
                    l = mid;
                else
                    r = mid;
            }

            if(g[r1 + i][c1 + l] < g[r2 + i][c2 + l])
                return -1;
            else 
                return 1;
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    vector<string> a(n);
    for (auto &s : a) cin >> s;

    g.resize(2 * n);
    for (int i = 0; i < 2 * n; i++)
        g[i] = a[i % n] + a[i % n];

    int R = 2 * n, C = 2 * m;

    h.assign(R, vector<long long>(C + 1));
    p.assign(C + 1, 1);

    for (int i = 1; i <= C; i++)
        p[i] = p[i - 1] * B % MOD;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            long long v = g[i][j] - '0' + 1;
            h[i][j + 1] = (h[i][j] + v * p[j]) % MOD;
        }

    long long invB = pw(B, MOD - 2);
    inv.assign(C + 1, 1);

    for (int i = 1; i <= C; i++)
        inv[i] = inv[i - 1] * invB % MOD;

    int br = 0, bc = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            if (cmp(i, j, br, bc) < 0)
                br = i, bc = j;
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << g[br + i][bc + j];
        cout << '\n';
    }
}