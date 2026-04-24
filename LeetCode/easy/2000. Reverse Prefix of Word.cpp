#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int i = 0;

        while(i < word.size() && word[i] != ch){
            i++;
        }

        if (i == word.size()) return word;

        int k = 0;

        while (k < i){
            swap(word[k], word[i]);
            i--;
            k++;
        }

        return word;
    }
};