#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n, num;

    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++){

        cin >> v[i];
    }

    int l = 0, r = n-1;
    long long lsum=0, rsum = 0;
    int lmin = l, rmin = r;
    int min_diff = abs(v[l] - v[r]);
    lsum += v[l];
    rsum += v[r];

    while(l < r){

        //cout << l << " h " << r << " " << min_diff << " s " << lmin << " h " << rmin << " " << lsum << " d " << rsum << endl;


        if(abs(rsum - lsum) < min_diff){
            min_diff = abs(rsum - lsum);
            lmin = l; 
            rmin = r;
        }

        if(rsum < lsum){
            r--;
            rsum += v[r];
        } else {
            l++;
            lsum += v[l];
        }

    }

    cout << min_diff << " " << lmin+1 << " " << rmin+1;

}