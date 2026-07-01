#include <iostream>

int main() 
{

    int n;

    std::cin >> n;

    int k;
    std::cin >> k;
    long long ans = 0;

    for(int i = 1; i < n; ++i){
        int num;
        std::cin >>num;

        ans += std::min(num,k);
        k = num;
    }

    std::cout  << ans;


	return 0;
}
