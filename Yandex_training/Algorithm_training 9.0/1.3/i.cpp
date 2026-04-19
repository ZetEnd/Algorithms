#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    long long a,b,c,d;

    cin >> a >> b >> c >> d;
    long long min1, min2;

    long long min_a = b+1; // синие майки
    long long min_b = a+1; // красные майки
    long long min_c = d+1;
    long long min_d = c+1;


    if(a == 0 || c == 0){

        min1 = min_b;
        min2 = min_d;
    } else 

    if(b == 0 || d == 0){

        min1 = min_a;
        min2 = min_c;
    } else 
    if(min_a + min_c < min_b+min_d){
        min1 = min_a;
        min2 = min_c;
    } else{
        min1 = min_b;
        min2 = min_d;
    }


    cout << min1 << " " << min2;

    return 0;
}