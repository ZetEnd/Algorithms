#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){

    string line;
    vector<string> text;

    while(getline(cin, line) && line != "")
        text.push_back(line);


    text.push_back(line);
    size_t ind = 0;

    string buf;


    while(cin >> line){


        if(line == "Down"){
            if(ind < text.size())
                ++ind;
        }
        else if(line == "Up"){
            if(ind > 0)
                --ind;
        }
        else if(line == "Ctrl+X"){



            if(text[ind].empty()) continue;

            buf = text[ind];
            text.erase(text.begin()+ind);

        }
        else if(line == "Ctrl+V"){

            if(buf != ""){
                text.insert(text.begin()+ind, buf);
                ++ind;
            }
        }

    }

    
    

    bool first = true;

    for(string& s: text){
        if(!first)
            cout << "\n";
        first = false;
        cout << s;
    }
}