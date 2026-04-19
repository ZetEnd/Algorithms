#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(){
    
    int n, m, k;

    cin >> n >> m >> k;

    vector<stack<char>> s(n);
    string buf = "";
    string type;
    //stack<char> c;

    int num = 0;
    int len;
    int count;

    for(int i = 0; i < m; i++){

        cin >> type;
        if( type == "Next"){
            num = (num+1)%n;
        }
        else if(type == "Backspace"){
            if(c.size() != 0)
                c.pop();

        }
        else if(type == "Copy"){
            len = s[num].size();
            count = min(len, k);
            buf = s[num].substr(len-count, count);
        }
        else if(type == "Paste")
            s[num] += buf;
        else 
            s[num] += type;
    }

    if(s[num].empty() == true)
        cout << "Empty";
    else {
        len = s[num].size();
        count = min(len, k);
        cout << s[num].substr(len-count, count);
    }

}