#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    string s;

    cin >> s;

    stack<char> st;

    bool flag = false;

    for(char c: s){
        /*if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }*/

        switch(c){
            case ')':
                if (st.size() == 0 || st.top() != '('){
                    flag = true;
                } else 
                    st.pop();
            break;

            case ']':
                if (st.size() == 0 || st.top() != '['){
                    flag = true;
                } else 
                    st.pop();
            break;

            case '}':
                if (st.size() == 0 || st.top() != '{'){
                    flag = true;
                } else 
                    st.pop();
            break;

            default:
                st.push(c);
        }

        if (flag) break;

    }

    if(st.size() == 0 && !flag)
        cout << "yes";
    else   
        cout << "no";
}