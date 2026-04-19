#include <iostream>

int func(int k){
if (k == 1) return 2;
if (k == 2) return 4;
if (k == 3) return 7;

long long f1, f2, f3, fn;
    f1 = 2;
    f2 = 4;
    f3 = 7;
    //fn = 0;

if (k == 1) return f1;
if (k == 2) return f2;
if (k == 3) return f3;
    
    
for(int i = 4; i <= k; i++){
    fn = f1 + f2 + f3;
    f1 = f2;
    f2 = f3;
    f3 = fn;
    }    
return fn;
}
int main(){

int N;
std::cin >> N;
   
int K = func(N);
std::cout << K;

return 0;
}