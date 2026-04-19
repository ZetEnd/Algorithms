#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){

    int n, k, num;

    cin >> n >> k;

    vector<int> res;
    vector<int> v;

    deque<int> d;

    for(int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);

        if(i-k >= 0 && d.front() == v[i-k])
            d.pop_front();

        while(d.size() != 0 && num < d.back()){
            d.pop_back();
        }
        d.push_back(num);

        if(i+1 >= k){
            res.push_back(d.front());
        }

    }


    for(int i = 0; i < res.size(); i++){

        cout << res[i] << endl;
    }


}