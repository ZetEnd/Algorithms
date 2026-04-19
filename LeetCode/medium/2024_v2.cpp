#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int maxn = -1;
        int know = k;
        int i = 0, n = answerKey.size();

        for(int j = 0; j < n; j++){

            if(answerKey[j] == 'F') know--;

            while(know < 0){
                if(answerKey[i] == 'F') know++;
                i++;
            }

            maxn = max(maxn, j-i+1);
        }

        know = k;
        i = 0;

        for(int j = 0; j < n; j++){

            if(answerKey[j] == 'T') know--;

            while(know < 0){
                if(answerKey[i] == 'T') know++;
                i++;
            }

            maxn = max(maxn, j-i+1);
        }

        return maxn;
    }
};