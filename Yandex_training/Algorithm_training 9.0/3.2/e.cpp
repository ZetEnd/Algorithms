#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    int n,k;
    string s;

    cin >> n >> k >> s;

    map<int,int> m;
    int l = 0, cur_max = 0, start = 0;

    for(int r = 0; r < n; r++){
        m[s[r]]+=1;

        while(m[s[r]] > k){
            m[s[l]]--;
            l++;
        }

        if(r - l+1 > cur_max){
            cur_max = r-l+1;
            start = l+1;
        }
    }

    cout << cur_max << " " << start;
}