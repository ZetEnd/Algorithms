#include <iostream>

using namespace std;

int main(){

    int n, res = -1, count = 0, num, rn = 0;

    cin >> n;

    while(count < n){

        cin >> num;

        if(num == 1){
            rn++;
        } else {
            res = max(res, rn);
            rn = 0;
        }

        count++;

    }

    res = max(res, rn);

    cout << res;
    
    return 0;
}