#include <iostream>
#include <map>


using namespace std;

int main(){


    int n;

    cin >> n;

    map<string,int> score;
    string name;

    for(int i = 0; i < n; i++){
        cin >> name;

        score[name] = 0;
    }

    int m;
    cin >> m;

    int a,b, a_old = 0, b_old = 0, max = 0;
    char point;
    string winner;

    for(int i = 0; i < m; i++){

        cin >> a >> point >> b >> name;

        score[name] += (a-a_old) + (b-b_old);

        a_old = a;
        b_old = b;

        if(score[name] > max){
            max = score[name];
            winner = name;
        }

    }

    cout << winner << " " << max;


    return 0;
}