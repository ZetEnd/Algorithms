#include <iostream>
using namespace std;

int main() {
    int N, C, R;
    cin >> N >> C >> R;

    int lost[101] = {0};
    int reserve[101] = {0};

    for (int i = 0; i < C; i++) {
        int x;
        cin >> x;
        lost[x] = 1;
    }

    for (int i = 0; i < R; i++) {
        int x;
        cin >> x;
        reserve[x] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (lost[i] && reserve[i]) {
            lost[i] = 0;
            reserve[i] = 0;
        }
    }

    int answer = N;

    for (int i = 1; i <= N; i++) {
        if (lost[i]) {
            if (reserve[i - 1]) {
                reserve[i - 1] = 0;
            }
            else if (reserve[i + 1]) {
                reserve[i + 1] = 0;
            }
            else {
                answer--;
            }
        }
    }

    cout << answer << endl;
}


/*
#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, C, R;
    cin >> N >> C >> R;

    set<int> lost;
    set<int> reserve;

    for (int i = 0; i < C; i++) {
        int x;
        cin >> x;
        lost.insert(x);
    }

    for (int i = 0; i < R; i++) {
        int x;
        cin >> x;
        reserve.insert(x);
    }

    // люди у которых и потеряна карта и есть запасная
    for (auto it = lost.begin(); it != lost.end(); ) {
        if (reserve.count(*it)) {
            reserve.erase(*it);
            it = lost.erase(it);
        } else {
            ++it;
        }
    }

    for (int x : lost) {
        if (reserve.count(x - 1)) {
            reserve.erase(x - 1);
        }
        else if (reserve.count(x + 1)) {
            reserve.erase(x + 1);
        }
        else {
            N--;
        }
    }

    cout << N << endl;
}
    */