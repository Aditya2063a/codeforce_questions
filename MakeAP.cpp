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
        int a, b, c;
        cin >> a >> b >> c;

        int new_a = b - (c - b);
        if (new_a >= a && new_a % a == 0 && new_a != 0)
        {
            cout << "YES\n";
            continue;
        }

        int new_b = a + (c - a) / 2;
        if (new_b >= b && (c - a) % 2 == 0 && new_b % b == 0 && new_b != 0)
        {
            cout << "YES\n";
            continue;
        }

        int new_c = a + 2 * (b - a);
        if (new_c >= c && new_c % c == 0 && new_c != 0)
        {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
}