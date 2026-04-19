#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

int main() {

    int N;
    std::cin >> N >> std::ws;

    int (* numbers)[3] = new int[N][3];

    int x;
    
    int left = 0, right = 0;
    for (int i = 0; i < N; i++)
    {

        std::string str;
        std::getline(std::cin, str);
        std::istringstream stream(str);

        int n = 0;

        while (stream >> x) {
            numbers[i][n] = x;
            //std::cout << numbers[i][n]  <<" ";
            n++;

        }
        left += numbers[i][0]*numbers[i][2];
        right += numbers[i][1]*numbers[i][2];
        //std::cout << std::endl;

    }
    
    int res = fabs(left-right)/100;
    
    std::cout << res;
    // put your code here
    return 0;
}