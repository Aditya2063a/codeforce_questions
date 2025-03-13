#include <bits/stdc++.h>
using namespace std;

int solve(string& str) {
    stack<string> st;
    
    for (int i = 0; i < str.length(); i++) {
        string ch(1, str[i]);
        
        if (st.empty()) {
            st.push(ch);
        } else {
            string top = st.top();
            string s = top + ch;
            if (s == "AB" || s == "BB") {
                st.pop();
            } else {
                st.push(ch);
            }
        }
    }
    
    return st.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        
        int result = solve(str);
        cout << result << "\n";
    }
    return 0;
}
