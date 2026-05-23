#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){

    int n, num;

    cin >> n;

    vector<int> v;

    unordered_set<int> s;

    while(n > 0){
        cin >> num;

        if(!s.count(num)){
            v.push_back(num);
            s.insert(num);
        }

        n--;

    }

    for(int x:v){
        cout << x << endl;
    }
}