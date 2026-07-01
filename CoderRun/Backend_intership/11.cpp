#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){

    int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = min1;

    int num;
    int c_zero = 0;

    while(cin >> num){

        if(num == 0) c_zero++;
        if(num > max1){
            max2 = max1;
            max1 = num;
        }
        else if(num > max2)
            max2 = num;

        if(num < min1){
            min2 = min1;
            min1 = num;
        }
        else if(num < min2)
            min2 = num;
    }

    long long res1 = (long long)max1*max2;
    long long res2 = (long long)min1*min2;

    if(res1 < res2)
        cout << min1 << " " << min2;
    else    
        cout << max2 << " " << max1;

    //cout << res;
}