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

    vector<string> buf;

    bool shift = false;
    size_t i_shift;


    while(cin >> line){



        if(line == "Down"){
            if(ind + 1 < text.size())
                ++ind;
        }
        else if(line == "Up"){
            if(ind > 0)
                --ind;
        }
        else if(line == "Ctrl+X"){



            if(shift){
                shift = false;

                if(text[ind].empty() && ind == i_shift)
                continue;   


                if(i_shift < ind){
                    buf.assign(text.begin()+i_shift, text.begin()+ind);
                    text.erase(text.begin()+i_shift, text.begin()+ind);

                    ind = i_shift;

                } else if(i_shift > ind){

                    buf.assign(text.begin()+ind, text.begin()+i_shift);
                    text.erase(text.begin()+ind, text.begin()+i_shift);
                } else {
                    buf = {text[ind]};
                    text.erase(text.begin()+ind);
                }


            } else {

                if(text[ind].empty())
                continue;   
        
                buf = {text[ind]};
                text.erase(text.begin()+ind);
            }

        }
        else if(line == "Ctrl+V"){

            if(buf.empty())
                continue;

            if(shift){
                shift = false;

                if(i_shift < ind){
                    text.erase(text.begin()+i_shift, text.begin()+ind);
                    text.insert(text.begin()+i_shift, buf.begin(), buf.end());

                    ind = i_shift + buf.size();
                    
                } else if(i_shift > ind){

                    text.erase(text.begin()+ind, text.begin()+i_shift);
                    text.insert(text.begin()+ind, buf.begin(), buf.end());

                    ind = ind + buf.size();
                } else {
                    text.insert(text.begin()+ind, buf.begin(), buf.end());
                    ind = ind + buf.size();
                }



            } else {
                text.insert(text.begin()+ind, buf.begin(), buf.end());
                ind = ind + buf.size();
            }

        }
        else if (line == "Shift"){
            if(!shift)
                i_shift = ind;
            shift = true;
        }
        else if (line == "Buf"){
            for(string s : buf){
                cout << "\n" << " buf = ";
                cout << s << " ";
            }
        }
        else if (line == "ind"){
            cout << "\n ind = " << ind;
        }
        else if (line == "i_shift"){
            cout << "\n i_shift = " << i_shift;
        }
        else if (line == "file"){
            for(const string& str: text)
                cout << " " << str;
        }


    }

    

    for(string& s: text){
        cout << s << '\n';
    }
}