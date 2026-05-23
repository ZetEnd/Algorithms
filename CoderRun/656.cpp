#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<vector<int>> v(26, vector<int>());

    while(n > 0){

        string s,t;

        cin >> s >> t;

        v = vector<vector<int>>(26, vector<int>());

        for(size_t i = 0; i != s.size(); i++){
            v[s[i] - 'A'].push_back(i);
        }
                

        int flag = 1;
        int num = s.size();

        for(int i = t.size()-1; i >= 0; i--){

            if( v[t[i] - 'A'].empty() || v[t[i] - 'A'].back() > num){
                flag = 0;
                break;
            } else {
                num = v[t[i] - 'A'].back();
                v[t[i] - 'A'].pop_back();
            }

        }

        if(flag)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
        n--;
    }
}