#include <iostream>

using namespace std;

int main(){

    int x,y,x1,y1;

    cin >> x >> y >> x1 >> y1;

    if(x == x1 || y == y1 || abs(y1-y) == abs(x1-x))
        cout << "YES";
    else    
        cout << "NO";
}