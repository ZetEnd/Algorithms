#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){

    string line;

    unordered_map<string, string> path;

    while(cin >> line){

        
        if(line.size() == 1) continue;

        string word = "/", up = "/";

        for(size_t i = 1; i != line.size();i++){

            word += line[i];

            if(line[i] == '/'){
                path[word] = up;
                up = word;
            }
        }
        if(!word.empty())
            path[word] = up;

    }

    map<string, string> ways1;
    for(const auto& [k,v] : path){
        ways1[v] = k;
        //cout << "k = " << k << " v = " << v << endl;
    }

    for(const auto& [k,v] : ways1){
        cout << k << endl;
    }

}