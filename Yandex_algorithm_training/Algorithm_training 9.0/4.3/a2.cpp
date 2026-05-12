#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(){

    string s;
    getline(cin, s);

    stack<int> st;

    for(char c : s){

        if(c == ' ')
            continue;

        //cout << "s = " << c;

        if(isdigit(c))
            st.push(c - '0');
        else{

            if(st.size() >= 2){
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();

                if(c == '+')
                    st.push(x1+x2);
                if(c == '-')
                    st.push(x2-x1);
                if(c == '*')
                    st.push(x1*x2);
            }
        }
    }

    cout << st.top();
}