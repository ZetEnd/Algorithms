#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){

    stack<int> st;

    int n, num, number = 1;
    cin >> n;

    /*for(int i = 0; i < n; i++){

        cin >> num;

        if(num == number){
            number++;
            while(st.size() != 0 && st.top() == number){
                st.pop();
                number++;
            }
        } else{
            st.push(num);
        }
    }*/

    for(int i = 0; i < n; i++){

        cin >> num;

        st.push(num);

        while(st.size() != 0 && st.top() == number)
        {
            st.pop();
            number++;
        }
    }

    if(st.size() == 0) cout << "YES";
    else cout << "NO";
}