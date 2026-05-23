#include <iostream>
#include <vector>

using namespace std;

vector<string> v;

void gen(int n, int open, int close, string s){

    if(open == n && close == n){
        v.push_back(s);
    }

    if(open < n){
        gen(n, open + 1, close, s + '(');
    }

    if(close < open)
        gen(n, open, close + 1, s + ')');
}

int main(){

    int n;

    cin >> n;

    if(n == 0)
        cout << "";

    gen(n,0,0,"");

    for(string& str : v){
        cout << str << endl;
    }


}

/*
#include <iostream>
#include <vector>

using namespace std;

void gen(int n, int open, int close, string s, vector<string>& v){

    if(open == n && close == n)
        v.push_back(s);

    if(open < n)
        gen(n, open + 1, close, s + '(', v);

    if(close < open)
        gen(n, open, close+1, s + ')', v);

}


int main(){

    int n;

    cin >> n;

    vector<string> v;

    gen(n, 0, 0, "", v);

    for(string& s:v)
    cout << s << endl;

}
*/