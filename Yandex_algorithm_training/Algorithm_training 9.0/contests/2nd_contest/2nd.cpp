#include <iostream>
using namespace std;

int main(){
    long long n,m,h,w;

    cin >> n >> m >> h >> w;

    long long num1=0, num2=0, ncopy = n, mcopy = m;

    while(ncopy > h){
        ncopy = (ncopy+1)/2;
        num1++;
    }
    while(mcopy > w){
        mcopy = (mcopy+1)/2;
        num1++;
    }

    ncopy = n;
    mcopy = m;

    while(ncopy > w){
        ncopy = (ncopy+1)/2;
        num2++;
    }
    while(mcopy > h){
        mcopy = (mcopy+1)/2;
        num2++;
    }

    if(num1 < num2) cout << num1;
    else cout << num2;
}