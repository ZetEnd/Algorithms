#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<string> vs;

    string s;

    while(getline(cin, s))
        vs.push_back(s);

    sort(vs.begin(), vs.end(), greater<string>());

    for(string out : vs)
        cout << out << "\n";
}