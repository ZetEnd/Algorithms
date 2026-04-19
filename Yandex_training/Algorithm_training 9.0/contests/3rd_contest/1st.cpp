#include <iostream>
#include <string>
using namespace std;

int main(){

    string s;
    getline(cin, s);

    string res = "";
    int i = 0;

    while(i < s.size()){

        if(s[i] == ' '){
            i++;
            continue;
        }

        int left = 0;
        while(i < s.size() && s[i] == 39){
            left++;
            i++;
        }

        string slovo = "";
        while(i < s.size() && s[i] != 39 && s[i] != 32){
            slovo += s[i];
            i++;
        }

        int right = 0;
        while(i < s.size() && s[i] == 39){
            right++;
            i++;
        }

        for(int j = left; j < slovo.size() - right; j++){
            res += slovo[j];
        }
    }

    cout << res << endl;
}