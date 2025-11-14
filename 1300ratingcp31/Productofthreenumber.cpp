#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

vector<pii> factors(int n){
    vector<pii> f;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0) n/=i, cnt++;
            f.pb({i,cnt});
        }
    }
    if(n>1) f.pb({n,1});
    return f;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pii> f = factors(n);

        if(f.size() >= 3){
            cout << "YES\n";
            cout << f[0].f << " " << f[1].f << " " << n / (f[0].f * f[1].f) << "\n";
            continue;
        }

        if(f.size() == 1){
            int p = f[0].f, k = f[0].s;
            if(k < 6) cout << "NO\n"; 
            else{
                cout << "YES\n";
                cout << p << " " << p*p << " " << n / (p*p*p) << "\n";
            }
            continue;
        }

        if(f.size() == 2){
            int p1 = f[0].f, k1 = f[0].s;
            int p2 = f[1].f, k2 = f[1].s;

            int a = p1;
            int b = p2;
            int c = n / (a * b);

            if(c > 1 && c != a && c != b) {
                cout << "YES\n" << a << " " << b << " " << c << "\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
