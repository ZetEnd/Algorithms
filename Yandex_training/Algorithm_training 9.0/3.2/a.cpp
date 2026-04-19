#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main(){

    int n,m,num;

    cin >> n;

    vector<int> v,b;

    for(int i = 0; i < n; i++){

        cin >> num;

        v.push_back(num);
    }

    cin >> m;

    for(int i = 0; i < m; i++){

        cin >> num;

        b.push_back(num);
    }

    int i = 0, j = 0;
    int cmin = INT_MAX;
    int imin = 0, jmin = 0;

    while(i < n && j < m){
        
        int cur = abs(v[i] - b[j]);

        if(cur < cmin){

            cmin = cur;
            imin = v[i];
            jmin = b[j];
        }

        if(v[i] > b[j]) j++;
        else i++;
    }


    cout << imin << " " << jmin;

}