#include <iostream>
#include <stack>

using namespace std;

int main(){

    int n, num;

    cin >> n;
    int count = 0;

    //stack<int> st;

    stack<pair<int, int>> st;

    for(int i = 0; i < n; i++){

        cin >> num;


        if(st.size() != 0 && st.top().first != num){

            //st.push({num, 1});
            if(st.size() != 0 && st.top().second >= 3){
                count += st.top().second;
                st.pop();
            }

            if(st.size() != 0 &&  st.top().first == num){
                int sec = st.top().second + 1;
                st.pop();
                st.push({num, sec});
            } else 
            st.push({num, 1});

        } else {
            if(st.size() == 0) st.push({num, 1});
                int sec = st.top().second + 1;
                st.pop();
                st.push({num, sec});

        }

    }

    while(st.size() != 0){
        if(st.top().second >= 3){
            count += st.top().second;
        }
        st.pop();
    }

    cout << count;
}