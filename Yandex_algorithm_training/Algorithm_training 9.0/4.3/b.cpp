#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

bool isnum(string s){

    bool flag = true;

    for( unsigned char c : s){
        if(!isdigit(c)){
            flag = false;
            break;
        }
    }

    return flag;
}

int eval_postfix(stack<string> tok){

    stack<int> st;
    vector<string> v;

    while(tok.size() > 0){
        v.push_back(tok.top());
        tok.pop();
    }

    reverse(v.begin(), v.end());

    for(string s : v){

        if(isnum(s)){
            int num = stoi(s);
            st.push(num);
        } else if(st.size() > 1){

            int x1 = st.top();
            st.pop();
            int x2 = st.top();
            st.pop();

            if(s == "+")
                st.push(x2+x1);
            if(s == "-")
                st.push(x2-x1);
            if(s == "*")
                st.push(x2*x1);
        }
    }

    return st.top();
}


stack<string> make_postfix(vector<string> infix_tokens){
    
    set<string> ops = {"+", "-", "*"};
    set<string> brackets = {"(", ")"};

    string prev_type = "op";

    stack<string> st;
    stack<string> postfix_tokens;
    stack<string> wrong;

    wrong.push("WRONG");

    for(string tokens : infix_tokens){

        if(ops.find(tokens) != ops.end() && prev_type != "num"){
            return wrong;
        }
        if(ops.find(tokens) != ops.end()){

            while((tokens == "*" && st.size() > 0 && st.top() == "*") ||  ( (tokens == "+" || tokens == "-")
             && (st.size() > 0 && ops.find(st.top()) != ops.end()) )  )
             {
                postfix_tokens.push(st.top());
                st.pop();
             }

            st.push(tokens);
            prev_type = "op";
            
        } else {
            
            if(isnum(tokens)){

                if(prev_type == "num")
                    return wrong;

                postfix_tokens.push(tokens);
                prev_type = "num";
            } else 
            if(brackets.find(tokens) != brackets.end()){

                if(tokens == "("){
                    if(prev_type == "num")
                        return wrong;

                    st.push(tokens);
                    prev_type = "bracket";
                } else {

                    while(st.size() > 0 && st.top() != "("){
                        postfix_tokens.push(st.top());
                        st.pop();
                    }

                    if(st.size() == 0) // неккоректная ПСП
                        return wrong;

                    st.pop(); // удалили скобку (
                }
            }
            else return wrong; // если не встретили ни число, ни опреацию, ни скобку
        }
    }

    if(prev_type != "num")
        return wrong;

    while(st.size() > 0){
        if (st.top() == "(")
            return wrong;

        postfix_tokens.push(st.top());
        st.pop();
    }

    return postfix_tokens;
}

int main(){

    string s;
    getline(cin, s);

    if(s[0] == '-')
        s = "0" + s;

    int pos = 0;
    
    while( (pos = s.find("(-", pos)) != string::npos ){
        s.replace(pos, 2, "(0-");
        pos+=3;
    }

    set<char> sym = {'(', ')', '+', '-', '*'};

    string res;
    for(char c : s){
        if(sym.find(c) != sym.end()){
            res += ' ';
            res += c;
            res += ' ';
        }
        else{
            res += c;
        }
    }

    s = res;

    //cout << res;

    istringstream iss(s);
    vector<string> v;

    while(iss >> res){
        v.push_back(res);
        //cout << res;
    }

    stack<string> tokens = make_postfix(v);

    if(tokens.size() == 1)
        cout << tokens.top();
    else 
        cout << eval_postfix(tokens);
}