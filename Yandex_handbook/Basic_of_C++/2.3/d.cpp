#include <iostream>

using namespace std;

int main(){

    int month, n;

    cin >> month >> n;

    bool flag = true;

    if(n % 400 == 0)
        flag = true;
    else if(n % 100 == 0)
        flag = false;
    else if (n % 4 == 0)
        flag = true;
    else 
        flag = false;

    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << 31;
            break;
        case 2:
            if(flag)
                cout << 29;
            else 
                cout << 28;
            break;
        default:
            cout << 30;

    }
}