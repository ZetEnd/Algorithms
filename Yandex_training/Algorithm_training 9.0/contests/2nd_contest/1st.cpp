#include <iostream>
#include <string>
using namespace std;

int main(){

    int n;
    string s;
    cin >> n;
    cin >> s;

    int max_len = 0;
    int cur_len = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == 'h' || s[i] =='a'){
            if(i > 0 && (s[i-1] == 'h' || s[i-1] == 'a')){
                if(s[i-1] != s[i]){
                    cur_len += 1;
                } else {
                    cur_len = 1;
                }
            } else cur_len = 1;
        } else {
            cur_len = 0;
        }

        if(cur_len > max_len) max_len = cur_len;
    }

    cout << max_len << endl;
}