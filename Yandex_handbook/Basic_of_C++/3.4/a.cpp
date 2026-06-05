#include <iostream>
#include <stack>

using namespace std;

int main(){

    char c;

    stack<char> st;

    int flag = 1;

    while(cin >> c){

        if(c == ')')
            if(!st.empty() && st.top() == '(') st.pop();
            else flag = 0;
        else if(c == '}')
            if(!st.empty() && st.top() == '{') st.pop();
            else flag = 0;
        else if (c == ']')
            if(!st.empty() && st.top() == '[') st.pop();
            else flag = 0;
        else 
            st.push(c);

        if(!flag) break;
    }

    if(flag && st.empty()) cout << "YES";
    else cout << "NO";
}