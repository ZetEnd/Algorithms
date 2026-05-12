#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){


    int num;
    int max1 = -1;
    int max2 = -1;
    int min1 = 1;
    int min2 = 1;
    int flag = 0;
    int count = 0;

    while(cin >> num)
    {

        count++;

        if (num > 0){

            if (num > max1){

                if(max1 > max2)
                    max2 = max1;

                max1 = num;
                
            } else if(num > max2)
                        max2 = num;

        }else{

            if (num < min1){
                if(min1 < min2)
                    min2 = min1;
                min1 = num;
            } else if(num < min2)
                        min2 = num;
        }
        
    }

    if (count == 2){
        cout << min1 << " " << max1;
    } else {
        long long mult_max = (long long)max1*max2;
    long long mult_min = (long long)min1*min2;

    //cout << mult_max << " " << mult_min;

    if(mult_max > mult_min){
        cout << max2 << " " << max1;
    } else {
        cout << min1 << " " << min2;
    }

    }


    return 0;
}