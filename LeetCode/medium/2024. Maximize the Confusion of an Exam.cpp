#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int maxn = -1;
        int know = k;
        int j = 0, n = answerKey.size();

        for(int i = 0; i < n; i++){

            while(j < n && know >= 0){
                if(answerKey[j] == 'F')
                    know--;
                    j++;
            }

            if(know < 0 ){
                j--;
                know++;
            }

            maxn = max(maxn, j - i);

            if(answerKey[i] == 'F') know++;
        }

        know = k;
        j = 0;

        for(int i = 0; i < n; i++){

            while(j < n && know >= 0){
                if(answerKey[j] == 'T')
                    know--;
                    j++;
            }

            if(know < 0 ){
                j--;
                know++;
            }

            maxn = max(maxn, j - i);

            if(answerKey[i] == 'T') know++;
        }

        return maxn;
    }
};