#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;
int main() 
{
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
