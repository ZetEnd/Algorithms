class Solution {
public:

    vector<vector<int>> forout(const string& s){

        unordered_map<int,int> hash;
        int cur = 1;

        vector<int> v;

        vector<vector<int>> res(s.size());

        for(int i = 0; i < s.size(); i++){

            if(hash[s[i]] == 0){
                hash[s[i]] = cur;
                cur++;
                v.push_back(1);
            } else{
                v[hash[s[i]]-1] += 1;
            }

            res[i] = v;
        }

        return res;

    }

    bool isIsomorphic(string s, string t) {
        

        vector<vector<int>> out1 = forout(s);
        vector<vector<int>> out2 = forout(t);

        for(int i = 0; i < out1.size(); i++)
            if(out1[i] != out2[i])
                return false;

        return true;

    }
};