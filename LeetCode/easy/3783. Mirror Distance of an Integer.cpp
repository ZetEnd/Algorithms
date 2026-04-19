#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int k = 0;
        int rn = n;

        while(rn > 0){
            k = k*10 + (rn % 10);
            rn = rn / 10;
        }

        return abs(n-k);
        
    }
};