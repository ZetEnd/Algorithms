#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int num;
    vector<int> v;

    while(cin >> num){
        v.push_back(num);
    }   

    int l = 0, r = v.size()-1;

    long long vol = 0;
    long long max_v = 0;

    while(l < r){

        vol = min(v[l],v[r])*(r-l+1);
        max_v = max(vol, max_v);

        if(l < r && v[l] < v[r]) l++;
        if(l < r && v[l] >= v[r]) r--;
    }

    cout << max_v;

	return 0;
}
