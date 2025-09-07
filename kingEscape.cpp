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
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a1, a2;
    cin >> a1 >> a2;
    int b1, b2;
    cin >> b1 >> b2;
    int c1, c2;
    cin >> c1 >> c2;

    bool res = true;

    if((b1<a1 && c1>a1) || (b1>a1 && c1<a1)){
        res = false;
    }

    if((b2<a2 && c2>a2) || (b2>a2 && c2<a2)){
        res = false;
    }
    if(res) cout << "YES\n";
    else cout << "NO\n";
}