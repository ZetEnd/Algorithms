class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int i;

        for(i = 0; i < strs[0].size(); i++){

            for(int k = 0; k < strs.size(); k++){

                if(i == strs[k].size() || strs[0][i] != strs[k][i])
                    return strs[0].substr(0,i);
            }
        }

        if(i == strs[0].size())
            return strs[0];
        else
            return "";
    }
};