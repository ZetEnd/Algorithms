#include <iostream>
#include <vector>
#include <map>


using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> a;
    int num;

    for (int i = 0; i < n; i++) {

        cin >> num;
        a.push_back(num);
    }

    map<long long, int> count;

    int l = 0;
    int res = 0;

    for (int i = 0; i < n; i++) {
        count[a[i]]++;

        while (count.size() > 2) {
            count[a[l]]--;
            if (count[a[l]] == 0) {
                count.erase(a[l]);
            }
            l++;
        }

        if (count.size() == 2) {
            if(i - l + 1 > res)
                res =  i - l + 1;
        }
    }

    cout << res;
}