#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){

    size_t n,k;

    cin >> n >> k;

    vector<int> v(n);
    deque<int> d;

    for(size_t i = 0; i < n; ++i){
        cin >> v[i];
        if(i==0) d.push_back(i);
        else 
            if(i < k) {
                while(!d.empty() && v[d.back()] > v[i])
                    d.pop_back();
                d.push_back(i);
            }
    }

    cout << v[d.front()] << endl;

    for(size_t i = k; i < n; ++i){
        
        if((size_t)d.front() == i - k)
            d.pop_front();

        while(!d.empty() && v[d.back()] > v[i])
            d.pop_back();
        d.push_back(i);
        
        cout << v[d.front()] << endl;
    }


}