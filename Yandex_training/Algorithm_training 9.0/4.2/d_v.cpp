#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(){

    int n;

    cin >> n;

    string w,s;
    stack<char> st;
    vector<char> res;

    cin >> w >> s;

    for(char c:s){
        if(c == '[' || c == '(')
            st.push(c);
        if(c == ']' && st.top() == '[')
            st.pop();
        if(c == ')' && st.top() == '(')
            st.pop();

    }

    for(int i = 0; i < n - s.size(); i++){

        for(char c : w){

            if(c == ')' && st.size() != 0 && st.top() == '('){
                res.push_back(c);
                st.pop();
                break;
            }
            if(c == ']' && st.size() != 0 && st.top() == '['){
                res.push_back(c);
                st.pop();
                break;
            }
            //if(c == '(' && n - s.size() - i > st.size()){
            if(c == '(' && n - s.size() - i -1 > st.size()){
                res.push_back(c);
                st.push(c);
                break;
            }
            if(c == '[' && n - (int)s.size() - i -2 >= (int)st.size()){

                //cout << " n = " << n - (int)s.size() - i -2 << " s = " << st.size();
                res.push_back(c);
                st.push(c);
                break;
            }
        }
    }

    for(char c: res){
        s += c;
    }

    cout << s;


}