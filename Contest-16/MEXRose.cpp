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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> freq(n + 1, 0);
        for (int x : a) freq[x]++;

        int missing = 0;
        for (int i = 0; i < k; ++i) if (freq[i] == 0) ++missing;

        int cntk = freq[k];
        cout << max(missing, cntk) << "\n";
    }
    return 0;
}