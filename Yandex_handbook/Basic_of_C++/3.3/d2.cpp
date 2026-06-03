#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Approx(const vector<int>& v, int num){

        auto it = lower_bound(v.begin(),v.end(),num);

        if(it == v.begin())
            return *it;
        else if(it == v.end())
            return *(it-1);
        else if(*it == num)
            return num;
        else {

            int first = *(it-1);
            int second = *(it);

            if(abs(first-num) <= abs(second-num))
                return first;
            else 
                return second;
        }

}

int main(){

    int n,k;

    cin >> n >> k;
    vector<int> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    int num;

    for(int i = 0; i < k; ++i){

        cin >> num;
        cout << Approx(v,num) << '\n';
    }


}