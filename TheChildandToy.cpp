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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for(int i=0; i<n; i++){
        cin >> d[i];
    }
    
    int result= 0;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        result += min(d[a], d[b]);
    }

    cout << result << "\n";

}