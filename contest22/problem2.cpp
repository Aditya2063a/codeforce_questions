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

int dfs(int i, string& s, vector<int>& dp, int& n) {
    if (i < 0 || i >= n){ 
        return 0;
    }

    if (dp[i] != -1){
        return dp[i];
    }

    if (s[i] == '<') {
        if (i == 0){ 
            return dp[i] = 1;
        }
        return dp[i] = 1 + dfs(i - 1, s, dp, n);
    }

    if (s[i] == '>') {
        if (i == n - 1){ 
            return dp[i] = 1;
        }
        return dp[i] = 1 + dfs(i + 1, s, dp, n);
    }

    int left = (i == 0 ? 0 : dfs(i - 1, s, dp, n));
    int right = (i == n - 1 ? 0 : dfs(i + 1, s, dp, n));
    return dp[i] = 1 + max(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        vector<int> dp(n+1, -1);
        bool in = false;
        for (int i = 0; i + 1 < n; i++) {
            bool rr = (s[i] == '>' || s[i] == '*');      
            bool le  = (s[i+1] == '<' || s[i+1] == '*');   
            if (rr && le) {
                in = true;
                break;
            }
        }

        if (in) {
            cout << -1 << "\n";
            continue;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, s, dp, n));
        }

        cout << ans << "\n";
    }
    return 0;
}
