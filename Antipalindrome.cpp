#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    if (!isPalindrome(s)) {
        cout << n << "\n";  
    } else {
        bool allSame = true;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[0]) {
                allSame = false;
                break;
            }
        }
        if (allSame) cout << 0 << "\n"; 
        else cout << n - 1 << "\n";
    }
}
