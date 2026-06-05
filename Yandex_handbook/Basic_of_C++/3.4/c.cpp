#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){

    string cmd;

    priority_queue<int> pq;

    while(cin >> cmd){

        if(cmd == "ADD"){
            int n;
            cin >> n;

            pq.push(n);
        }
        else if(cmd == "CLEAR"){
            if(!pq.empty())
                pq = {};
        }
        else if(cmd == "EXTRACT"){
            if(!pq.empty()){
                cout << pq.top() << endl;
                pq.pop();
            } else 
                cout << "CANNOT" << endl;

        }
    }
}