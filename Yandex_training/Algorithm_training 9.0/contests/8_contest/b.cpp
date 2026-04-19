#include<iostream>
#include<vector>

using namespace std;

int main(){

    int num;

    cin >> num;

    long long n,d;
    vector<int> res;

    for(int i = 0; i < num; i++){

        cin >> n >> d;
        vector<long long> t(n), k(n), prefsum(n);
        long long w = 0;

        for(int i = 0; i < n; i++){
            cin >> t[i] >> k[i];
            prefsum[i] = t[i] - w;
            w+= k[i];
        }


        vector<long long> sufmin = prefsum;
        for(int i = n-2; i >= 0; i--){
        
            if(sufmin[i+1] < sufmin[i])
                sufmin[i] = sufmin[i+1];
        }

        int l = 0, r = n;

        while(l < r){

            int m = l + (r-l)/2;
            if(sufmin[m] >= d) 
                r = m;
            else 
                l = m + 1;
        }

        res.push_back(l+1); 

    }

    for(int x: res){
        cout << x << endl;
    }
}