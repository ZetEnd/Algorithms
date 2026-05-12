#include <iostream>
#include <string>
using namespace std;

int main(){

    string s;

    cin >> s;

    int l = s.size();

    int n;
    int sum = 0;
    int min_estimate = 0;

    for(char c: s){
        n = c - 'A';
        sum += n;

        if (n > min_estimate)
            min_estimate = n;
    }

    int a = sum/l;
    if (2 * (sum % l) > l)
        a++;

    int final_estimate = max(min_estimate - 1, a);

    char res = 'A' + final_estimate;

    cout << res;
}