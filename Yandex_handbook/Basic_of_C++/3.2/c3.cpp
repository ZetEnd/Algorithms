#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){

    string line;

    set<string> path;

    while(cin >> line){

        
        if(line.size() == 1) continue;

        string word = "/", up = "/";

        for(size_t i = 1; i != line.size();i++){

            word += line[i];

            if(line[i] == '/'){
                path.insert(up);
                up = word;
            }
        }
        if(!word.empty())
            path.insert(up);

    }

    for(const auto& s : path){
        cout << s  << endl;
    }


}