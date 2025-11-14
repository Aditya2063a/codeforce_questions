// #include <bits/stdc++.h>
// using namespace std;
// #include <numeric> 

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
//         ll ans=n, a=1, b=n;
//         for(ll i=1; i<n; i++){
//             if(ans>lcm(n-i, i)){
//                 ans=lcm(n-i,i);
//                 a=n-i;b=i;
//             }
//         }

//         cout<< a << " " << b <<"\n";
//     }
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	cin >> t;
	while (t--) {
		int n; 
		cin >> n;
		int f = 0; 
		for (int i = 2; i * i <= n; i++) { 
			if (n % i == 0) { 
				int k = n / i;
				cout << k << " " << n - k << endl; 
				f = 1; 
				break;
			}
		}
		if (f == 0) {
			cout << 1 << " " << n - 1 << endl;
		}
	}
}

