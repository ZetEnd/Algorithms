#include <iostream>

using namespace std;

int main(){

    int n, k;

    cin >> n >> k;

    int num = 1;

    int i = 1;
    while(i < n){
        cout << "   ";
        i++;
    }
    while(num <= k){

        if(num < 10)
            cout << " ";
        cout << num;
        if(i % 7 == 0)
            cout << "\n";
        else 
            if(num != k)
                cout << " ";
        num++;
        i++;
    }
    cout << "\n";

}