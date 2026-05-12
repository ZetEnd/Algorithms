#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 0) {
        cout << -2;
        return 0;
    }

    stack<pair<int, int>> st;

    int destroyed = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

       
        if(!st.empty() && st.top().first == x){
            st.top().second++;
        } else {

            if(!st.empty() && st.top().second >= 3){
                destroyed += st.top().second;
                st.pop();

                if(!st.empty() && st.top().first == x){
                    st.top().second++;
                    continue;
                }
            }

            st.push({x,1});
        }


    }

    if(!st.empty() && st.top().second >= 3){
        destroyed += st.top().second;
        st.pop();
    }

    cout << destroyed;
    return 0;
}