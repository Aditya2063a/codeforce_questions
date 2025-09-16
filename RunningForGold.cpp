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

const int M = 5;
 
struct Rank {
    int r[M];
};
 
bool operator<(const Rank& A, const Rank& B) {
    int cnt = 0;
    for (int i = 0; i < M; i++) cnt += A.r[i] < B.r[i];
    return cnt >= 3;
}
 
void solve() {
    int n;
    cin >> n;
 
    vector<Rank> ath(n);
    for (int i = 0; i < n; i++) for (int j = 0; j < M; j++) cin >> ath[i].r[j];
    
    int gold = 0;
    for (int i = 1; i < n; i++) {
        if (ath[i] < ath[gold]) gold = i;
    }
 
    for (int i = 0; i < n; i++) {
        if (i == gold) continue;
        if (ath[i] < ath[gold]) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << gold+1 << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++) solve();
}