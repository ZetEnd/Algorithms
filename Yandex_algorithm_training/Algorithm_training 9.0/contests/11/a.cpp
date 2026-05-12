#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(){

    string s;
    getline(cin, s);

    stack<char> st;
    bool flag = true;
    bool global_flag = false;

    if(s.size() == 0){
        cout << "YES";
    } else {

    for(int i = 0; i < s.size(); i++){

        stack<char>().swap(st); 
        flag = true;

        for(int j = i; j < s.size()+i; j++){

            char c = s[j % s.size()];

            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else{
                if (st.size() == 0){
                flag = false;
                break;
                }

                if(c == ']' && st.top() != '['){
                    flag = false;
                    break;
                }

                if(c == ')' && st.top() != '('){
                    flag = false;
                    break;
                }


                if(c == '}' && st.top() != '{'){
                    flag = false;
                    break;
                }

                st.pop();

            }


        }

        if(flag && st.size() == 0){
        global_flag = true;
            break;
        }
    }

    if(s.size() %2 != 0){
        cout << "NO";
    } else {
        if(global_flag) cout << "YES";
            else cout << "NO";
    }

}



}