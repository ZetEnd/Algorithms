#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    map<char, int> cur;

    int l = 0;
    int max_len = 0;
    int start = 0;

    for (int r = 0; r < n; r++) {
        cur[s[r]]++;

        // если текущий символ превышает k → двигаем левую границу
        while (cur[s[r]] > k) {
            cur[s[l]]--;
            l++;
        }

        // обновляем ответ
        if (r - l + 1 > max_len) {
            max_len = r - l + 1;
            start = l;
        }
    }

    cout << max_len << " " << start + 1;
}