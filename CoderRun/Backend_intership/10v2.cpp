#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int main() 
{
	int num;
    vector<int> v;
    cin >> num;

    while(cin >> num){
        v.push_back(num);
    }   

    stack<pair<int,int>> st;
    vector<int> left(v.size(), v.size());

    for(int i = 0; i < v.size(); ++i){

        while(!st.empty() && st.top().first > v[i]){
            left[st.top().second] = i;
            st.pop();
        }
        st.push({v[i], i});
    }

    vector<int> right(v.size(),-1);
    while(!st.empty())
        st.pop();

    for(int i = v.size()-1; i >= 0; --i){

        while(!st.empty() && st.top().first > v[i]){
            right[st.top().second] = i;
            st.pop();
        }
        st.push({v[i], i});
    }

    long long s = 0;
    long long maxs = 0;
    for(int i = 0; i < v.size(); ++i){
        s = (left[i] - right[i]-1)*(long long)v[i];
        maxs = max(s,maxs);
    }

    cout << maxs;

	return 0;
}
