#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){

    int n;
    string s;

    vector<long long> v{0};
    cin >> n >> s;

    int num = 0;
    int count = 0;

    map<long long, long long> uniq;
    uniq[0] = 1;

    for(char c: s){

        if(c == 'a') num = 1;
        else num = -1;

        v.push_back(v.back()+num);

        count += uniq[v.back()];
        uniq[v.back()] +=1;

    }

    cout << count;
}