#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */

    bool compare(string &s, string &t, int l, int r){
        while(l < s.size() && r < t.size() && s[l] == t[r]){
            l++;
            r++;
        }
        return l == s.size() && r == t.size();
    }
    bool isOneEditDistance(string &s, string &t) {
        // write your code here

        if(s == t) return false;
        int i = 0;

        while(i < s.size() && i < t.size() && s[i] == t[i])
            ++i;

        return compare(s,t,i+1,i+1) || compare(s,t,i+1, i) || compare(s,t,i, i+1);

    }
};