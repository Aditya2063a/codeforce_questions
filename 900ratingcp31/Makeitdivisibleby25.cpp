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

const string subseqs[] = { "00", "25", "50", "75" };

const int INF = 100;

int solve(string& s, string& t)
{
	int sptr = s.length() - 1;
	int ans = 0;
	while (sptr >= 0 && s[sptr] != t[1]){
		sptr--;
		ans++;
	}

	if (sptr < 0) return INF;
	sptr--;

	while (sptr >= 0 && s[sptr] != t[0]){
		sptr--;
		ans++;
	}

	return sptr < 0 ? INF : ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        string n;
		cin >> n;
		
		int ans = INF;
		for (auto e : subseqs)
			ans = min(ans, solve(n, e));

		cout << ans << '\n';
    }
}