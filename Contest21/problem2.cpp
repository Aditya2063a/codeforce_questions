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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        string x; cin >> x;

        bool bad = false;
        if (x[0] == '1' || x[n - 1] == '1') bad = true;
        for (int i = 0; i < n; ++i)
            if (x[i] == '1' && (p[i] == 1 || p[i] == n)) bad = true;
        if (bad) {
            cout << -1 << "\n";
            continue;
        }

        int mini=-1, maxa=-1;
        for(int i=0; i<n; i++){
            if (x[i]==1){
                mini=i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(x[i]==1){
                maxa=i;
                break;
            }
        }

        int minVal = *min_element(p.begin() + mini, p.begin() + maxa + 1);
        int maxVal = *max_element(p.begin() + mini, p.begin() + maxa + 1);
        
        int min1=-1, max1=-1, min2=-1, max2=-1;
        for(int i=0; i<mini; i++){
            min1=min(minVal, p[i]);
            max1=max(maxVal, p[i]);
        }

        for(int i=maxa+1; i<n; i++){
            min2=min(minVal, p[i]);
            max2=max(maxVal, p[i]);
        }

        if((min1==minVal || min2==minVal) && max1==maxVal || max2==maxVal){
            cout<<0<<"\n";
        }else{
            cout<<1<<"\n";
            
        }
    }
}
