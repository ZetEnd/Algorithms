#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> grid; // 2N x 2M удвоенная матрица

// --- 1D хэши строк ---
const long long MOD1 = 1000000007LL, MOD2 = 998244353LL;
const long long B1 = 131, B2 = 137;
const long long Q1 = 1000003LL, Q2 = 999983LL;

vector<vector<long long>> sh1, sh2;       // prefix hashes строк удвоенной матрицы
vector<long long> pb1, pb2;               // степени B
vector<long long> inv1b, inv2b;           // обратные степени B
vector<vector<long long>> rH1c, rH2c;    // кэш rowHash[r][c]
vector<vector<long long>> gH1, gH2;      // глобальный хэш матрицы при сдвиге (r,c)
vector<long long> pq1, pq2;              // степени Q

long long pw(long long b, long long e, long long m) {
    long long r = 1; b %= m;
    while (e > 0) { if (e & 1) r = r*b%m; b = b*b%m; e >>= 1; }
    return r;
}

void build() {
    int R = 2*N, C = 2*M;
    sh1.assign(R, vector<long long>(C+1, 0));
    sh2.assign(R, vector<long long>(C+1, 0));
    pb1.resize(C+1); pb2.resize(C+1);
    pb1[0] = pb2[0] = 1;
    for (int j = 1; j <= C; j++) pb1[j]=pb1[j-1]*B1%MOD1, pb2[j]=pb2[j-1]*B2%MOD2;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            long long v = grid[i][j]-'0'+1;
            sh1[i][j+1] = (sh1[i][j] + v*pb1[j]) % MOD1;
            sh2[i][j+1] = (sh2[i][j] + v*pb2[j]) % MOD2;
        }

    inv1b.resize(C+1); inv2b.resize(C+1);
    long long ib1=pw(B1,MOD1-2,MOD1), ib2=pw(B2,MOD2-2,MOD2);
    inv1b[0] = inv2b[0] = 1;
    for (int j = 1; j <= C; j++) inv1b[j]=inv1b[j-1]*ib1%MOD1, inv2b[j]=inv2b[j-1]*ib2%MOD2;

    // Кэш хэшей строк rowHash(r,c) = хэш строки r столбцы [c, c+M)
    rH1c.assign(R, vector<long long>(M));
    rH2c.assign(R, vector<long long>(M));
    for (int r = 0; r < R; r++)
        for (int c = 0; c < M; c++) {
            rH1c[r][c] = (sh1[r][c+M]-sh1[r][c]+MOD1)%MOD1 * inv1b[c] % MOD1;
            rH2c[r][c] = (sh2[r][c+M]-sh2[r][c]+MOD2)%MOD2 * inv2b[c] % MOD2;
        }

    // Глобальный хэш матрицы: gH[r][c] = sum_{i=0}^{N-1} rH[r+i][c] * Q^i
    pq1.resize(N+1); pq2.resize(N+1);
    pq1[0] = pq2[0] = 1;
    for (int i = 1; i <= N; i++) pq1[i]=pq1[i-1]*Q1%MOD1, pq2[i]=pq2[i-1]*Q2%MOD2;

    long long iq1=pw(Q1,MOD1-2,MOD1), iq2=pw(Q2,MOD2-2,MOD2);
    gH1.assign(N, vector<long long>(M, 0));
    gH2.assign(N, vector<long long>(M, 0));

    // r=0: прямое вычисление
    for (int c = 0; c < M; c++) {
        for (int i = 0; i < N; i++) {
            gH1[0][c] = (gH1[0][c] + rH1c[i][c]*pq1[i]) % MOD1;
            gH2[0][c] = (gH2[0][c] + rH2c[i][c]*pq2[i]) % MOD2;
        }
    }
    // r=1..N-1: рекуррентно
    // gH[r][c] = (gH[r-1][c] - rH[r-1][c]) * invQ + rH[r-1+N][c] * Q^(N-1)
    for (int r = 1; r < N; r++)
        for (int c = 0; c < M; c++) {
            gH1[r][c] = ((gH1[r-1][c]-rH1c[r-1][c]+MOD1)%MOD1*iq1 + rH1c[r-1+N][c]*pq1[N-1]) % MOD1;
            gH2[r][c] = ((gH2[r-1][c]-rH2c[r-1][c]+MOD2)%MOD2*iq2 + rH2c[r-1+N][c]*pq2[N-1]) % MOD2;
        }
}

// Хэш строки r, первые len столбцов начиная с c
pair<long long,long long> rowHashPfx(int r, int c, int len) {
    long long v1=(sh1[r][c+len]-sh1[r][c]+MOD1)%MOD1*inv1b[c]%MOD1;
    long long v2=(sh2[r][c+len]-sh2[r][c]+MOD2)%MOD2*inv2b[c]%MOD2;
    return {v1,v2};
}

// Лексикографическое сравнение конкатенаций строк при сдвигах (r1,c1) и (r2,c2)
int compare(int r1, int c1, int r2, int c2) {
    for (int i = 0; i < N; i++) {
        if (rH1c[r1+i][c1]!=rH1c[r2+i][c2] || rH2c[r1+i][c1]!=rH2c[r2+i][c2]) {
            // Бинарный поиск первого различного символа в строке i
            int lo=0, hi=M;
            while (lo+1 < hi) {
                int mid=(lo+hi)/2;
                if (rowHashPfx(r1+i,c1,mid)==rowHashPfx(r2+i,c2,mid)) lo=mid;
                else hi=mid;
            }
            return grid[r1+i][c1+lo] < grid[r2+i][c2+lo] ? -1 : 1;
        }
    }
    return 0;
}

int main(){

    cin >> N >> M;
    vector<string> orig(N);
    for (auto& s : orig) cin >> s;

    grid.resize(2*N);
    for (int i = 0; i < 2*N; i++) grid[i] = orig[i%N] + orig[i%N];

    build();

    int bestr=0, bestc=0;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            if (r==0 && c==0) continue;
            // Если глобальный хэш совпадает с best — матрицы с высокой вероятностью одинаковы
            if (gH1[r][c]==gH1[bestr][bestc] && gH2[r][c]==gH2[bestr][bestc]) continue;
            if (compare(r, c, bestr, bestc) < 0) { bestr=r; bestc=c; }
        }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cout << grid[bestr+i][bestc+j];
        cout << '\n';
    }
    return 0;
}