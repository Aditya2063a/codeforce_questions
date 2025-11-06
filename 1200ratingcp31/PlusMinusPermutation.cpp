// #include <bits/stdc++.h>
// using namespace std;

// #define f first
// #define s second
// #define pb push_back

// typedef long long int ll;
// typedef unsigned long long int ull;
// typedef pair<int,int> pii;
// typedef pair<ll,ll> pll;

// #define mod 1000000007
// #define INF 1000000000

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     ll tt;
//     cin >> tt;
//     while (tt--) {
//         ll n,x,y;
//         cin>>n>>x>>y;
//         ll xx=0,yy=0;
//         for(ll i=1; i<n+1; i++){
//             if(i%x==0){
//                 xx++;
//             }
//             if(i%y==0){
//                 yy++;
//             }

//             if(i%x==0 && i%y==0){
//                 xx--;yy--;
//             }
//         }
//         ll ans=0;
//         for(ll i=n; i>n-xx; i--){
//             ans+=i;
//         }
//         for(ll i=1; i<yy+1; i++){
//             ans-=i;
//         }

//         cout<<ans<<"\n";
//     }
// }



#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 lcm(int64 a, int64 b) {
    return a / gcd(a, b) * b;
}

int64 range_sum(int64 l, int64 r) {
    if (l > r) return 0;
    return (l + r) * (r - l + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int64 n, x, y;
        cin >> n >> x >> y;

        int64 L = lcm(x, y);
        int64 plus = n / x - n / L;
        int64 minus = n / y - n / L;

        int64 ans = range_sum(n - plus + 1, n) - range_sum(1, minus);
        cout << ans << "\n";
    }

    return 0;
}
