#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main(){

    int count_step = 0;
    int n;

    queue<int> st1;
    queue<int> st2;

    for(int i = 0; i < 10; i++){

        cin >> n;
        if (i < 5)
            st1.push(n);
        else
            st2.push(n);
    }

    bool flag = true;
    int max = pow(10,6);

    int who = 0;

    while(count_step < max && flag){

        if(st1.front() > st2.front()){

            if(st2.front() == 0 && st1.front() == 9){
                who = 2;
            } else 
                who = 1;
        } else {

            if(st2.front() == 9 && st1.front() == 0)
                who = 1;
            else 
                who = 2;
        }

        if(who == 2){
            st2.push(st1.front());
            st2.push(st2.front());
        } else {
            st1.push(st1.front());
            st1.push(st2.front());
        }

        st1.pop();
        st2.pop();

        if(st1.empty() || st2.empty())
        flag = false;

        count_step++;
    }

    if(flag){
        cout << "botva";
    } else {
        if(st1.empty())
            cout << "second " << count_step;
        else    
            cout << "first " << count_step;
    }
}