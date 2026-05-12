#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    string s;


    cin >> n;
    cin >> s;
    cin >> m;

    vector<string> a(m);
    vector<int> right(m);
    vector<int> wrong(m);

    int c;

    for (int i = 0; i < m; i++) {
        cin >> a[i];

        c = 0;
        for (int k = 0; k < n; k++) {
            if (a[i][k] == s[k]) c++;
        }

        right[i] = c;
        wrong[i] = n - c;
    }

    vector<pair<int,int>> p;

    int right_num;
    int wrong_num;

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {

            right_num = 0;
            wrong_num = 0;

            for (int k = 0; k < n; k++) {
                if (a[i][k] == a[j][k]) {
                    if (a[i][k] == s[k]) right_num++;
                    else wrong_num++;
                }
            }

            if (right_num > right[i]/2 && right_num > right[j]/2 && wrong_num > wrong[i]/2 && wrong_num > wrong[j]/2) {
                p.push_back({i+1, j+1});
            }
        }
    }

    cout << p.size() << endl;


    for (pair<int,int> x : p) {
        cout << x.first << " " << x.second << endl;
    }

}