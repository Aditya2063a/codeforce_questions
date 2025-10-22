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

// ll lcm(ll a, ll b) {
//     return (a / __gcd(a, b)) * b;  
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int tt;
//     cin >> tt;
//     while (tt--) {
//         ll n; cin>>n;
//         ll left=1, right=n-1,a=left,b=right, ans=1e18;
//         while(left<=right){
//             if(ans>lcm(left,right)){
//                 a=left;b=right;
//                 ans=lcm(left,right);
//             }
//             left++;right--;
//         }

//         cout<<a<<" "<<b<<"\n";
//     }
// }

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        if (n % 2 == 0) {
            cout << n / 2 << " " << n / 2 << "\n";
            continue;
        }

        ll d = 1;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                d = max(d, max(i, n / i));
            }
        }

        if (d == 1)
            cout << 1 << " " << n - 1 << "\n";
        else
            cout << d << " " << n - d << "\n";
    }
}
