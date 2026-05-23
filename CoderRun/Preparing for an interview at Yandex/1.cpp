#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;
int main() 
{
	/*
	Пример ввода и вывода числа n, где -10^9 < n < 10^9:
	int n;
	std::cin >> n;
	std::cout << n << std::endl;
	*/

	string j,s;
	unordered_set<char> hash;

	cin >> j >> s;

	for(char c: j){
		hash.insert(c);
	}

	int res = 0;

	for(char c: s){
		if(hash.count(c))
			res++;
	}

	cout << res;

	return 0;
}
