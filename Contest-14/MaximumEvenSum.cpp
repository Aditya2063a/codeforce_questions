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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long ans = -1;

        if ((a + b) % 2 == 0)
            ans = max(ans, a + b);

        if (a % 2 == 1 && b % 2 == 1)
            ans = max(ans, a * b + 1);

        if (b % 2 == 0) {
            long long candidate = a * (b / 2) + 2;
            if (candidate % 2 == 0)  
                ans = max(ans, candidate);
        }

        cout << ans << "\n";
    }
    return 0;
}