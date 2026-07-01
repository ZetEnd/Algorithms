#include <iostream>
#include <unordered_map>
//#include 

using namespace std;

int main() 
{
	int k;
    string s;

    cin >> k;
    cin >> s;

    int max_len = 0;

    for(size_t i = 'a'; i <= 'z'; ++i){

        int k_now = 0;
        int l = 0;

        for(int r = 0; r < s.size(); ++r){

            if(s[r] != (char)i)
                k_now++;

            while(l < r && k_now > k){
                if(s[l] != (char)i)
                    k_now--;
                l++;
            }
            max_len = max(max_len, r-l+1);
        }
    }

    cout << max_len;

	return 0;
}
