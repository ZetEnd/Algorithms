#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main(){

    int n;

    cin >> n;
    int x,d;

    int num;

    int maxx = INT_MAX;
    int minx = INT_MIN;

    for(int i = 0; i < n; i++){

        cin >> x >> d;

        maxx = min(maxx, x+d);
        minx = max(minx, x - d);
    }

    if(maxx < minx){
        maxx = -1;
    }

    cout << maxx;

    return 0;
}