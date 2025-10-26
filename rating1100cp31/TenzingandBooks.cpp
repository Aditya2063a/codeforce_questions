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
        int n, x;
        cin >> n >> x;
        int s = 0;
        vector<int> a(n);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++) cin >> a[j];
            for (int j = 0; j < n; j++)
            {
                if ((x | a[j]) != x)
                    break;
                s |= a[j];
            }
        }
        if (s == x)
            cout << "YES"<<"\n";
        else
            cout << "NO"<<"\n";
    }
}