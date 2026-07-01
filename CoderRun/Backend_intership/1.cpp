#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    vector<string> vs;

    string line;

    unordered_set<string> words;

    while(getline(cin, line)){

        istringstream s(line);
        string temp;

        while(s >> temp){
            vs.push_back(temp);
            words.insert(temp);
        }

    }

    cout << words.size();
}