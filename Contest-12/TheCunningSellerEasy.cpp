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

using int64 = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;

        long long res = 0;
        int i = 0;
        while (n > 0) {
            int d = n % 3;  
            n /= 3;

            if (d > 0) {
                long long base = 1;
                for (int j = 0; j < i; j++) base *= 3;  
                long long dealCost;
                if (i == 0) {
                    dealCost = 3; 
                } else {
                    long long pow3i   = base;
                    long long pow3i_1 = base / 3; 
                    dealCost = (pow3i * 3) + (i * pow3i_1);
                }
                res += 1LL * d * dealCost;
            }
            i++;
        }
        cout << res << "\n";
    }
}
