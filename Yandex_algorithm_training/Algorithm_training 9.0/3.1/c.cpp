#include <iostream> 
#include <vector>
#include <climits>

using namespace std;

int main() {

    int n;
    cin >> n;

    int num;
    vector<int> arr(n+1);

    int maxsum = 0, minprefix = 0;

    for(int i = 1; i <= n; i++){

        cin >> num;
        arr[i] = arr[i-1] + num;

        if(arr[i] - minprefix > maxsum)
            maxsum = arr[i] - minprefix;

        if (arr[i] < minprefix)
            minprefix = arr[i];
    }

    cout << maxsum;

}