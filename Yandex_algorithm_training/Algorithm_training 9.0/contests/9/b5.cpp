#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    
    int n, k;
    cin >> n >> k;

    vector<long long> ps(n+1, 0);
    for(int i = 0; i < n; i++){
        long long x; cin >> x;
        ps[i+1] = ps[i] + x;
    }

    // minByRem[r] = минимальный prefix sum среди уже просмотренных с остатком r
    vector<long long> minByRem(k, LLONG_MAX);

    long long ans = 0;

    for(int r = 0; r <= n; r++){
        long long remR = ((ps[r] % k) + k) % k;

        // ps[r] — правый конец. Ищем минимальный ps[l] с остатком != remR
        for(int rem = 0; rem < k; rem++){
            if(rem != remR && minByRem[rem] != LLONG_MAX){
                ans = max(ans, ps[r] - minByRem[rem]);
            }
        }

        // Добавляем ps[r] как потенциальный левый конец для будущих r
        minByRem[remR] = min(minByRem[remR], ps[r]);
    }

    cout << ans;
}