#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
    int n;
    string w, s;
    
    cin >> n >> w >> s;
    
    // Порядок скобок
    map<char, int> order;
    for (int i = 0; i < 4; i++) order[w[i]] = i;
    
    string open = "([";
    string close = ")]";
    map<char, char> match = {{')', '('}, {']', '['}};
    
    stack<char> st;
    string result = s;
    
    // Проверяем корректность s
    for (char c : s) {
        if (open.find(c) != string::npos) {
            st.push(c);
        } else {
            if (st.empty() || match[c] != st.top()) {
                cout << "Error" << endl;
                return 1;
            }
            st.pop();
        }
    }
    cout << "s" << s.size();
    
    // Достраиваем
    for (int pos = s.length(); pos < n; pos++) {
        for (char c : w) {
            stack<char> temp = st;
            bool ok = false;
            
            if (open.find(c) != string::npos) {
                temp.push(c);
                int rem = n - pos - 1;
                if (rem >= (int)temp.size() && (rem - (int)temp.size()) % 2 == 0) {
                    ok = true;
                }
            } else {
                if (!temp.empty() && match[c] == temp.top()) {
                    temp.pop();
                    int rem = n - pos - 1;
                    if (rem >= (int)temp.size() && (rem - (int)temp.size()) % 2 == 0) {
                        ok = true;
                    }
                }
            }
            
            if (ok) {
                result += c;
                if (open.find(c) != string::npos) st.push(c);
                else st.pop();
                break;
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}