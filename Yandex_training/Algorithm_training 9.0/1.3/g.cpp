#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main(){

    int n = 10;
    vector<int> v;

    int num;

    for(int i = 0; i < n; i++){

        cin >> num;

        v.push_back(num);
    }

    int min = INT_MAX;
    int max = -1;

    for(size_t i = 0; i < n; i++){

        if(v[i] == 1){

            int j = i;
            int k = i;

            while(v[j] != 2){

                if(j == 0)
                {
                    j = i;
                    break;
                }
                j --;
            }
            while(v[k] != 2){
                if(k == n){
                    k = i;
                    break;
                }
                k++;
            }

            if(j != i && k != i){
                if(i-j < k-i) min = i-j;
                else min = k-i;

                if (min > max) max = min;

                min = INT_MAX;
            }else {
                if(k == i){
                    min = i-j;
                    if (min > max) max = min;
                    min = INT_MAX;
                }
                if(j == i){
                    min = k-i;
                    if (min > max) max = min;
                    min = INT_MAX;
                }
            }
        }

    }

    cout << max;
}