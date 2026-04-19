#include <iostream>

int func(int k){
if (k == 1) return 2;
if (k == 2) return 4;
if (k == 3) return 7;

return func(k-1) + func(k-2) + func(k-3);
}

int main(){

int N;
std::cin >> N;

int K = func(N);
std::cout << K;

return 0;
}