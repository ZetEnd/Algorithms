#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int type1 = -1, type2 = -1;
    int last_type = -1, last_count = 0;
    int cur_len = 0, res = 0;

    for (int i = 0; i < n; i++) {
        int x = a[i];

        if (x == type1 || x == type2) {
            cur_len++;
        } else {
            cur_len = last_count + 1;
        }

        if (x == last_type) {
            last_count++;
        } else {
            last_type = x;
            last_count = 1;
        }

        if (type1 == -1) {
            type1 = x;
        } else if (type2 == -1 && x != type1) {
            type2 = x;
        } else if (x != type1 && x != type2) {
            type1 = last_type;
            type2 = x;
            cur_len = last_count + 1; // это важно
        }

        // обновляем ответ только если есть ровно два типа
        if (type1 != type2) {
            res = max(res, cur_len);
        }
    }

    cout << res;
}