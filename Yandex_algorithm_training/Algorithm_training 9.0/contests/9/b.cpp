#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, k;

    cin >> n >> k;

    vector<long long> v(n);
    vector<long long> ps(n+1);


    for(int i = 0; i < n; i++){

        cin >> v[i];

        ps[i+1] = ps[i] + v[i]; 

        //cout << ps[i+1] << "  s ";
    }

    long long msum = 0;
    int r = n-1;

    for(int l = 0; l < n; l++){

        while(r >0 && (ps[r+1] - ps[l]) % k != 0){
            r--;
        }

        //cout << r << "  r " << ps[r] << " " << ps[l];

        if( r <= n)
            if (ps[r] - ps[l] > msum)
                msum = ps[r] - ps[l];

        if(r == l) r--;

    }

    cout << msum;


}