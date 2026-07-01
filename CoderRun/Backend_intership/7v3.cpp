#include <iostream>
#include <vector>

int main() 
{
	int num;

    std::cin >>num;

    std::vector<int> dp(num);

    // dp[i] - кол-во последовательностей без 3х едениц
    // для всехпоследовательности длины i 
    // если заканчиваетсч на 0 - dp[i-1]
    // если заканчивается на 01 - dp[i-2]
    // если заканчивается на 011 - dp[i-1]
    // дальше идут повторения

    dp[0] = 2;
    dp[1] = 4;
    dp[2] = 7;

    for(int i = 3; i <num; ++i){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    std::cout << dp[num-1];



	return 0;
}
