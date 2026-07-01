#include <iostream>
#include <algorithm>
#include <vector>

int main() 
{

    int n;
    long long ans = 0;

    std::cin >> n;
    std::vector<int> v(n);

    for(int i = 0; i < n; ++i)
        std::cin >> v[i];

    for(int i = 0; i+1 < n; ++i){
        if(v[i] < v[i+1])
            ans += v[i];
        else 
            ans += v[i+1];
    }

    std::cout  << ans;
    
	return 0;
}
