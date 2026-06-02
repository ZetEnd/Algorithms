#include <iostream>
#include <unordered_set>

using namespace std;

int main(){

    int num;
    unordered_set<int> s1;

    while(cin >> num){
        if(s1.count(num))
            cout << "YES\n";
        else{
            s1.insert(num);
            cout << "NO\n";
        }
    }
}