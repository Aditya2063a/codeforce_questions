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
        int N;
        cin >> N;

        int A[N];
        int ans = -1000000007;

        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }

        for (int i = 0; i < N; ++i)
        {
            ans = max(ans, A[(i - 1 + N) % N] - A[i]);
        }

        for (int i = 1; i < N; ++i)
        {
            ans = max(ans, A[i] - A[0]);
        }

        for (int i = 0; i < N - 1; ++i)
        {
            ans = max(ans, A[N - 1] - A[i]);
        }

        cout << ans << '\n';
    }
}