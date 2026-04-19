#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Submission{
public:
long long maximumTripletValue_V2(vector<int>& nums){

    int n = nums.size();

    if(n<3) return 0;

    int maxi = nums[0];
    int maxij = maxi - nums[1];
    long long res = maxij * nums[3];

    for(int i = 1; i < n-2; i++){

        maxi = max(maxi, nums[i]);
        maxij = max(maxij, maxi - nums[i+1]);
        res = max(res, (long long)maxij*nums[i+2]);
    }

    if(res < 0 ) res = 0;

}

};

int main(){

    Submission Sub;
    vector<int> input;

    string 

    while 
}