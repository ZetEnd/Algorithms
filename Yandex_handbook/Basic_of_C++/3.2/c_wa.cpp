#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void find_ways(auto& ways, string& up, const string& word){

    string way = up;
    while(ways.count(up)){
        way = ways[up] + way;
        up = ways[up];
    }

    ways[word] = way;

}

int main(){

    string line;

    unordered_map<string, string> path;

    while(cin >> line){

        
        if(line.size() == 1) continue;

        string word, up = "/";

        for(size_t i = 1; i != line.size();i++){


            word += line[i];

            if(line[i] == '/'){
                find_ways(path, up, word);
                up = word;
                word = "";
            }
        }
        if(!word.empty())
            find_ways(path, up, word);

    }

    map<string, string> ways1;
    for(const auto& [k,v] : path){
        ways1[v] = k;
        //cout << "k = " << k << " v = " << v << endl;
    }

    for(const auto& [k,v] : ways1){
        cout << k << endl;
    }


    /*

    vector<string> ways;

    for(const auto& [k,v] : path){
        ways.push_back(v);
        //cout << "k = " << k << " v = " << v << endl;
    }

    sort(ways.begin(), ways.end());

    for(const string& s: ways){
        cout << s << endl;
    }*/
}