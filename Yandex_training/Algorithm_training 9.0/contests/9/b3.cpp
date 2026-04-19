#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // Считаем prefix sums
    vector<long long> ps(n+1, 0);
    for(int i = 0; i < n; i++) ps[i+1] = ps[i] + a[i];

    long long total = ps[n];

    // Если сумма не делится на K — берём всё
    if(total % k != 0){
        cout << max(0LL, total);
        return 0;
    }

    // Иначе ищем максимум из двух вариантов:
    // 1) Убрать минимальный префикс с остатком != 0 (mod k)
    // 2) Убрать минимальный суффикс с остатком != 0 (mod k)

    long long ans = 0;

    // Вариант 1: ищем первый i (слева), где a[i] % k != 0
    // Тогда берём [i+1 .. n-1], сумма = total - ps[i+1]
    for(int i = 0; i < n; i++){
        if(a[i] % k != 0){
            ans = max(ans, total - ps[i+1]);
            break;
        }
    }

    // Вариант 2: ищем первый i (справа), где a[i] % k != 0
    // Тогда берём [0 .. i-1], сумма = ps[i]
    for(int i = n-1; i >= 0; i--){
        if(a[i] % k != 0){
            ans = max(ans, ps[i]);
            break;
        }
    }

    cout << ans;
    return 0;
}