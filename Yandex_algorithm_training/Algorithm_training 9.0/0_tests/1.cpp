#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string result = "";
    int i = s.size() - 1;

    while (i >= 0) {
        if (s[i] == '#') {
            int num = stoi(s.substr(i - 2, 2));
            result += (char)('a' + num - 1);
            i -= 3;
        } else {
            int num = s[i] - '0';
            result += (char)('a' + num - 1);
            i -= 1;
        }
    }

    reverse(result.begin(), result.end());
    cout << result << endl;

    return 0;
}