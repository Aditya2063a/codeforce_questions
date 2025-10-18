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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        map<int, int> freq;
        for (int x : a) freq[x]++;

        if (freq.size() == 1) {
            cout << "YES\n";
        } else if (freq.size() == 2) {
            auto it = freq.begin();
            int c1 = it->second;
            ++it;
            int c2 = it->second;
            if (abs(c1 - c2) <= 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            cout << "NO\n";
        }
        
    }
}