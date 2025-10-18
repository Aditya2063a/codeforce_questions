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
 
bool check(int x) {
    string s = to_string(x);
    int cnt = 0;
    for (char c : s) {
        if (c != '0') cnt++;
    }
    return cnt == 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> a;
    for (int i = 1; i < 1000000; i++) {
        if (check(i)) a.push_back(i);
    }

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int x : a) {
            if (x <= n) ans++;
        }
        cout << ans << "\n";
    }
}