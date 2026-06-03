#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n,k;

    cin >> n >> k;
    vector<int> v1(n);

    for(int i = 0; i < n; ++i){
        cin >> v1[i];
    }

    int num;

    for(int i = 0; i < k; ++i){
        cin >> num;
        int res;

        auto it = lower_bound(v1.begin(),v1.end(),num);

        if(it != v1.end())
            res = *it;
        else    
            res = *(it-1);

        if(it != v1.begin() && abs(*(it-1) - num) <= abs(res - num))
            res = *(it-1);

        cout << res << '\n';
    }


}