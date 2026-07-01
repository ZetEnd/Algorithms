#include <iostream>


// для последовательности F(N) - кол-во последовательностей без 3х 1 подряд
// вначале 0 или 1
// если 0 - прибавялем F(N-1) - first
// если 1, то рассматриваем 10 и 11
// если 10 - прибавляем F(N-2) - stcond
// если 11, то рассматриваем 110 и 111
// если 110 - прибавляем F(N-3) - third
// а 111 - не подходит

int F(int n){
    if(n == 1) return 2;
    if(n == 2) return 4;
    if(n == 3) return 7;

    int first = 2;
    int second = 4;
    int third = 7;

    int x = 4;
    int now = 0;

    while(x <= n){
        now = first + second + third;

        first = second;
        second = third;
        third = now;
        ++x;
    }

    return now;

}
int main() 
{
	int num;

    std::cin >>num;

    std::cout << F(num);

	return 0;
}
