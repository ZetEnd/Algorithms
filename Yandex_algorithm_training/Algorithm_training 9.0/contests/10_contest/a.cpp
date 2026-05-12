#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int n,m;

    cin >> n >> m;

    vector<string> s(n);

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(s[i][j] == '#'){

                if((i == 0 || s[i-1][j] == '.') && (j == 0 || s[i][j-1] == '.'))
                    count++;
            }
        }

    }

    cout << count;

    return 0;
}
