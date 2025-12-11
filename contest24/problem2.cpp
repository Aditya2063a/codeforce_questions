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

// int solve(vector<int>& a, vector<int>& b, int index, int n, vector<int>& dp){
//     if(index>=n){
//         return 0;
//     }

//     if(dp[index]!=-1){
//         return dp[index];
//     }
//     int first=0, second=0;


// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin>>n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];

        ll X = 0;           
        ll Y = INT_MIN;     
        for (int i = n - 1; i >= 0; --i) {
            ll newX = max(X - a[i], Y - b[i]);
            ll newY = max(Y + a[i], X + b[i]);
            X = newX; Y = newY;
        }
        cout << max(X, Y) << '\n';
    }
}