#include <iostream>
#include <string>

using namespace std;

int main(){

    int troom, tcond;
    string mode;

    cin >> troom >> tcond >> mode;

    if(mode == "freeze"){

        if(troom > tcond) troom = tcond;

    }else if(mode == "heat"){

        if(troom < tcond) troom = tcond;

    }else if(mode == "auto"){

        troom = tcond;
        
    }else if(mode == "fun"){

    }

    cout << troom;
    return 0;
}