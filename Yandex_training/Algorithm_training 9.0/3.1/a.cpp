#include <iostream>
#include <vector>

using namespace std;
int main(){

    int n;
    cin >> n;

    vector<int> arr;

    vector<int> prefixSum = {0};

    int num;

    for(int i = 0; i < n; i++){

        cin >> num;

        arr.push_back(num);
        prefixSum.push_back(prefixSum[i] + num);
    }

    for(int i = 1; i < prefixSum.size(); i++){
        cout << prefixSum[i] << " ";
    }

    return 0;
}