#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int li;
typedef unsigned long long int ull;
typedef pair<int,int> pii;

#define mod 1000000007
#define INF 1000000000

const int N = 200 * 1000 + 13;

int n;
int a[N];

inline void read() {	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

inline void solve() {
	int pos = -1;
	li ans0 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			pos = i;
		}
		if (pos != -1) {
			ans0 += pos + 1;
		}
	}	
	int cnt1 = 0, cnt2 = 0;
	int bal = 0;
	li ansP = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			cnt1 = 0, cnt2 = 0, bal = 0;
			continue;
		}
		if (bal % 2 == 0) {	
			cnt1++;
		} else {
			cnt2++;
		}
		if (a[i] < 0) {
			bal++;
		}
		if (bal % 2 == 0) {
			ansP += cnt1;
		} else {
			ansP += cnt2;
		}
	}
	cout << n * 1ll * (n + 1) / 2 - ans0 - ansP << ' ' << ansP << endl;
}

int main () {
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    srand(time(NULL));
    cerr << setprecision(10) << fixed;
    
    read();
    solve();
 
    //cerr << "TIME: " << clock() << endl;
}