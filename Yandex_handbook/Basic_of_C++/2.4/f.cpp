#include <iostream>
#include <vector>

using namespace std;

int main(){

    int m,n,k;

    cin >> m >> n >> k;

    vector<vector<int>> v(m, vector<int>(n));

    for(int i = 0; i < k; i++){
        int x,y;
        cin >> x >> y;

        x--;
        y--;

        v[x][y] = (int)'*';

        if(x-1 >= 0){
            v[x-1][y] += 1;
            if(y+1 <= n-1)
                v[x-1][y+1] += 1;
            if(y-1 >= 0)
                v[x-1][y-1] += 1;
        }

        if(x+1 <= m-1){
            v[x+1][y] += 1;
            if(y+1 <= n-1)
                v[x+1][y+1] += 1;
            if(y-1 >= 0)
                v[x+1][y-1] += 1;
        }

        if(y+1 <= n-1)
            v[x][y+1] += 1;
        if(y-1 >= 0)
            v[x][y-1] += 1;

        
            
    }

    for(size_t i = 0; i < v.size(); i++){
        for(size_t j = 0; j < v[0].size(); j++){

            if(v[i][j] >= 42)
                cout << '*' << ' ';
            else
                cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}