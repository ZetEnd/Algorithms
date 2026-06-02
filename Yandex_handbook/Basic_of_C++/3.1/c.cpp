#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

void MakeTrain(){

    
    string command;

    deque<int> d;

    while(getline(cin, command)){

        istringstream ss(command);

        char operation;
        string side;
        size_t num;

        ss >> operation >> side >> num;

        if(operation == '+'){
            if(side == "left") d.push_front(num);
            else d.push_back(num);
        }
        else if(operation == '-'){
            if(num >= d.size()) d.erase(d.begin(), d.end());
            else{
                if(side == "left") d.erase(d.begin(),d.begin() + num);
                else d.erase(d.end() - num ,d.end());
            }
        }

    }

    for(const auto& x: d){
        cout << x << " ";
    }
    cout << "\n";

}

int main(){

    MakeTrain();
}