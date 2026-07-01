#include <iostream>
#include <unordered_map>

using namespace std;

int main() 
{
	int n;

    cin >> n;

    unordered_map<string, string> hash;

    for(int i = 0; i  < n; ++i){
        string w1,w2;

        cin >> w1 >> w2;

        hash[w1] = w2;
        hash[w2] = w1;
    }

    string word;

    cin >> word;

    cout << hash[word];


	return 0;
}
