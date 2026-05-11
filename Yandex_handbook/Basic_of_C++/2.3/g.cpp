#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n;
    cin >> n;

    double s = 1;
    int del = 2;
    for(int i = 1; i < n; i++){
        s += pow(-1,i) / del;
        del++;
    }

    cout << s;
}