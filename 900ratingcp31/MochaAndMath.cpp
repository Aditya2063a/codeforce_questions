#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define mod 1000000007
#define INF 1000000000

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int res = a[1];
        for (int i = 2; i <= n; i++)
            res &= a[i];
        cout << res << endl;
    }
}