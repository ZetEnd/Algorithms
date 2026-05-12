#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main(){

    int n,m;

    cin >> n;

    string w, s = "";

    stack<char> ws, st, st_reverse;

    cin >> w >> s;

    for(char c:s){
        //st.push(c);

        switch(c){

                case '(':
                    st_reverse.push(')');
                    break;

                case ')':

                    if(st.size() != 0 && st.top() == '('){
                        if(st_reverse.size() != 0) st_reverse.pop();
                    } else 
                    st_reverse.push('(');
                    break;

                case '[':
                    st_reverse.push(']');
                    break;

                case ']':
                    if(st.size() != 0 && st.top() == '['){
                        if(st_reverse.size() != 0) st_reverse.pop();
                    } else 
                    st_reverse.push('[');
                    break;
            }

            st.push(c);
    }


    //cout << "s";

    int length = s.size();

    //cout << "s" << s.size();

    for(int i = 0; i < n - 2*length; i++){

        for(int k = 0; k < w.size(); k++){

            bool flag = true;

            switch(w[k]){

                case '(':
                    if(st.size() != 0 && (st.top() == ')' || st.top() == ']')){

                        st.push(w[k]);
                        if(w[k] == st_reverse.top())
                            st_reverse.pop();
                        flag = false;
                    } else {
                        if(st.size() == 0){
                            st.push(w[k]);
                            flag = false;
                        }
                    }
                    break;

                case ')':
                    if(st.size() != 0 && st.top() == '('){

                        st.push(w[k]);
                        if(w[k] == st_reverse.top())
                            st_reverse.pop();
                        flag = false;
                    }
                    break;

                case '[':
                    if(st.size() != 0 && (st.top() == ')' || st.top() == ']')){

                        st.push(w[k]);
                        if(w[k] == st_reverse.top())
                            st_reverse.pop();
                        flag = false;
                    } else {
                        if(st.size() == 0){
                            st.push(w[k]);
                            flag = false;
                        }
                    }
                    break;

                case ']':

                    if(st.size() != 0 && st.top() == '['){

                        st.push(w[k]);
                        if(w[k] == st_reverse.top())
                            st_reverse.pop();
                        flag = false;
                    }
                    break;
            }

            if(!flag) break;
        }
    }

    int len = st_reverse.size();

    //cout << "ss";

    for(int i = 0; i < len; i++){
        st.push(st_reverse.top());
        st_reverse.pop();

    }

    string out = "";
    //cout << "sss";

    while(st.size()!=0){
        out+= st.top();
        st.pop();
    }

    reverse(out.begin(), out.end());

    cout << out;

    return 0;
}
