#include <iostream>
#include <vector>

using namespace std;

int main(){

    int a,b,c;

    cin >> a >> b >> c;

    if(c < 0){
        cout << "NO SOLUTION";
    } else if(a == 0){

        if(b >= 0 && b == c*c){
            cout << "MANY SOLUTIONS";
        } else {
            cout << "NO SOLUTION";
        }
    } else {

        if((c*c -b) % a == 0){
            int x1 = (c*c -b) / a;
            if(a*x1 + b == c*c){
                cout << x1;
            } else {
                cout << "NO SOLUTION";
            }
        } else {
            cout << "NO SOLUTION";
        }


    }

}