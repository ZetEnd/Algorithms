#include <bits/stdc++.h>
using namespace std;


class ZigzagIterator {
public:

    vector<int> v1,v2;
    int index1, index2;
    bool first;
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        // do intialization if necessary
        this->v1 = v1;
        this->v2 = v2;

        index1 = index2 = 0;
        if(!v1.empty())
            first = true;
        else 
            first = false;
    }

    /*
     * @return: An integer
     */
    int next() {

        int res;
        // write your code here
        if(first){
            res = v1[index1];
            ++index1;
            if(index2 < v2.size()) first = !first;
        } else {
            res = v2[index2];
            ++index2;
            if(index1 < v1.size()) first = !first;
        }

        return res;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        // write your code here
        return index1 < v1.size() || index2 < v2.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */