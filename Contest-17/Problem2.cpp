#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
#define mod 1000000007
#define INF 1000000000

bool is_palindrome(const string &s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        ++i; --j;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        if (is_palindrome(s)) {
            cout << 0 << "\n";
            continue;
        }
        
        char c = s[0];
        vector<int> idx;
        for (int i = 0; i < n; ++i) if (s[i] == c) idx.push_back(i + 1);
        
        cout << idx.size() << "\n";
        for (int i = 0; i < (int)idx.size(); ++i) {
            if (i) cout << ' ';
            cout << idx[i];
        }
        cout << "\n";
    }
    return 0;
}
