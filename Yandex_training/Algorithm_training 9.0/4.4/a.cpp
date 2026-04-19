#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){

    int n, num;
    cin >> n;

    vector<int> res(n);

    stack<pair<int, int>> st;


    for(int i = 0; i < n; i++){
        cin >> num;


            while(st.size() != 0 && num < st.top().first ){

                res[ st.top().second ] = i;
                st.pop();

            }

            st.push({num, i});
        }

    while(st.size() != 0){
        res[ st.top().second ] = -1; 
        st.pop();
    }

    for(int i = 0; i < n; i++){

        cout << res[i] << " ";
    }


}