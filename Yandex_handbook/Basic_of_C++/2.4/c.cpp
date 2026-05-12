#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, num;
    cin >> n;

    vector<int> v;

    while(n > 0){
        cin >> num;
        v.push_back(num);
        n--;
    }

    vector<int> res(v.size());

    for(size_t i = 0; i < v.size(); i++){
        res[v[i]-1] = i+1;
    }

    for(size_t i = 0; i != res.size(); i++){
        cout << res[i] << " ";
    }

}