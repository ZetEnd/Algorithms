#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){

    int n;
    cin >> n;

    deque<string> d;

    for(int i = 0; i < n; ++i){
        string name, where;

        cin >> name >> where;

        if(where == "top")
            d.push_front(name);
        else 
            d.push_back(name);
    }

    cin >> n;

    for(int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        cout << d[--j] << "\n";
    }

}