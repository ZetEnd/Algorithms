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
    }

    long long msum = 0;

    if(ps[n] % k != 0){
        msum = ps[n];
    }


  

    cout << msum;


}