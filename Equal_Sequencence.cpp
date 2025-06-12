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
    int t; 
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string result = string(k, '1') + string(n - k, '0');

        cout << result << "\n";
    }
    return 0;
}
