#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    //string s;
    char num;
    char c = ' ';
    stack<int> s;

    long long res = 0;

    int n;
    while(cin >> num){

        //cin >> num;

        if(num == '+'){

            if(s.size() > 1){
                n = s.top();
                s.pop();

                res = n + s.top();
                s.pop();
                s.push(res);
            }
        }
        else
        if(num == '-'){
            if(s.size() > 1){
                n = s.top();
                s.pop();

                res = s.top() - n;
                s.pop();
                s.push(res);
            }

        }
        else
        if(num == '*'){

            if(s.size() > 1){
                n = s.top();
                s.pop();

                res = s.top() * n;
                s.pop();
                s.push(res);
            }
            
        }
        else
            if(num != ' ')
            s.push(num-'0');

        /*if(s.size() != 0)
        cout << "top = " << s.top();
        cout << " n = " << num;*/

    }

    cout << s.top();
}