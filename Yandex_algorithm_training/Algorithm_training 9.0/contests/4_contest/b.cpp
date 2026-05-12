#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<string> arr;
    string word;

    unordered_map<string, int> pairs;
    int len;

    for (int i = 0; i < n; i++) {
        cin >> word;
        arr.push_back(word);
    }
    len = word.size();

    bool flag = false;
    int res = 0;
    int l = 0, r = len;

    auto can = [&](int k) {
        pairs = {};

        for(int i = 0; i < n; i++){
            pairs[arr[i].substr(0,k)] +=1;
        }

        for(auto x:pairs){
            if(x.second % 2 != 0)
             return false;

        }

        return true;
    };

    while (l <= r) {

        int mid = (l + r) / 2;
        if (can(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << res;

    return 0;
}