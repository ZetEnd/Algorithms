#include <iostream>
#include <stack>

using namespace std;
int main() 
{
	char ch;

    stack<char> st;

    bool flag = true;

    while(cin >> ch && flag){

        if(ch == '[' || ch == '(' || ch == '{')
            st.push(ch);
        if(ch == ')')
            if(!st.empty() && st.top() == '(')
                st.pop();
            else
                flag = false;
        if(ch == ']')
            if(!st.empty() && st.top() == '[')
                st.pop();
            else
                flag = false;
        if(ch == '}')
            if(!st.empty() && st.top() == '{')
                st.pop();
            else
                flag = false;
    }

    if(st.empty() && flag)
        cout << "yes";
    else 
        cout << "no";
	return 0;
}
