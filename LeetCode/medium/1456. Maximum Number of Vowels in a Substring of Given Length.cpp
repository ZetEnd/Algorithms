#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        
        int len = s.size(), j = 0;
        int maxn = 0, res = -1;

        for(int i = 0; i < len; i++){
            while(j < len && j-i < k){
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    maxn++;
                j++;
            }
            res = max(res, maxn);

            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                maxn--;
        }

        return res;
    }
};