#include <iostream>

using namespace std;

int main(){

    int a,b,c;

    cin >> a >> b >> c;

    int maxv = max(a,b);
    int minv = min(a,b);
    maxv = max(maxv,c);
    minv = min(minv,c);

    int mid = a+b+c - maxv - minv;

    if(maxv >= minv+mid)
        cout << "UNDEFINED";
    else if(maxv*maxv == minv*minv + mid*mid)
        cout << "YES";
    else 
        cout << "NO";
}