#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){

    string text;

    list<string> edit;
    list<string> buffer;

    while(getline(cin , text) && text != "")
        edit.push_back(text);

    auto iter = edit.begin();

    auto shift_it = iter;
    bool shift = false;

    int offset = 0;

    while(cin >> text){

        if(text == "Down"){
            if(iter != edit.end()){
                ++iter;
                if(shift)
                    offset++;
            }
        }
        if(text == "Up"){
            if(iter != edit.begin()){
                --iter;
                if(shift)
                    offset--;
            }
        }
        if(text == "Ctrl+X"){

            if(shift){
                if(iter == shift_it && iter == edit.end()) continue;
            }
            else    
                if(iter == edit.end()) continue;

            buffer.clear();

            if(shift){
                
                if(offset > 0)
                    buffer.splice(buffer.begin(), edit, shift_it, iter);
                else if(offset < 0){
                    buffer.splice(buffer.begin(), edit, iter, shift_it);
                    iter = shift_it;
                }
                else if(offset == 0){

                    auto it = iter;
                    ++iter;
                    buffer.splice(buffer.begin(), edit, it);
                }

                shift = false;
            } else {

                auto it = next(iter);
                buffer.splice(buffer.begin(), edit, iter);
                iter = it;
            }

        }
        if(text == "Ctrl+V"){

            if(buffer.empty()) continue;

            if(shift){
                if(offset > 0){
                    edit.erase(shift_it, iter);
                    edit.insert(iter, buffer.begin(), buffer.end()); 
                } else if(offset < 0){
                    edit.erase(iter, shift_it);
                    edit.insert(shift_it, buffer.begin(), buffer.end()); 
                    iter = shift_it;
                } else if(offset == 0){
                    edit.insert(iter, buffer.begin(), buffer.end()); 
                }

                shift = false;
            } else {
                edit.insert(iter, buffer.begin(), buffer.end()); 
            }

        }
        if(text == "Shift"){
            if(!shift){
                shift_it = iter;
                offset = 0;
            }
            shift = true;
        }
        if(text == "buffer"){
            for(auto s : buffer)    
                cout << " " << s;
            cout << "\n";
        }
    }

    for(const string& s: edit)
        cout << s << '\n';
    
}