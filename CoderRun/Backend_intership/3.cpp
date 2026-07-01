#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){

    int n, k;

    cin >> n >> k;

    vector<int> v(n);

    deque<int> deq;

    for(int i = 0; i < n; i++)
        cin >> v[i];

    deq.push_back(0);

    for(int i = 1; i < k; i++){
        while(!deq.empty() && v[i] <= v[deq.back()])
            deq.pop_back();

        deq.push_back(i);
    }

    vector<int> res;
    
    for(int i = k-1; i < n; i++){

        while(!deq.empty() && v[i] <= v[deq.back()])
            deq.pop_back();

        deq.push_back(i);

        while(deq.front() <= i-k)
            deq.pop_front();

        res.push_back(v[deq.front()]);
    }

    for(int num : res){
        cout << num << endl;
    }


}