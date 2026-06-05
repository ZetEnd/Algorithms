#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main(){

    int n,k;
    cin >> n >> k;

    queue<int> q;
    multiset<int> mset;

    for(int i = 0; i < n; ++i){
        int num;

        cin >> num;

        q.push(num);
        mset.insert(num);
        if(i>=k-1){
            cout << *mset.begin() << endl;
            auto it = mset.find(q.front());
            mset.erase(it);
            q.pop();
        }
    }
}