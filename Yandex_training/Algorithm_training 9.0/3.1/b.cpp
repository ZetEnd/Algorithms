#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> arr;

    vector<long long> presum(n);

    int num;

    for(int i = 0; i < n; i++){

        cin >> num;
        arr.push_back(num);

        if (i == 0){
            presum[i] = num;
        } else {
            presum[i] = presum[i-1] + arr[i];
        }
    }

    int q;
    long long X0, X1,L,R;

    cin >> q >> X0;

    X1 = (11173*X0+1)%1000000007;

    L = min(X0 % n, X1 % n);
    R = max(X0 % n, X1 % n);

    long long res;

    if(L == 0) res = presum[R];
    else res = presum[R] - presum[L-1];


    for(int i = 1; i < q; i++){

        X0 = (11173*X1+1)%1000000007;
        X1 = (11173*X0+1)%1000000007;

        L = min(X0 % n, X1 % n);
        R = max(X0 % n, X1 % n);

        //cout << presum.size() << "  " << n << endl;
        //cout << X0 << "  " << X1 << " " << i << endl;
        //cout << L << "  " << R << " " << i << endl;

        if(L == 0) res += presum[R];
        else res += presum[R] - presum[L-1];
    }

    cout << res % 1000000007;

    return 0;
}