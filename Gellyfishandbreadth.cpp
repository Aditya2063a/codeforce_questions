#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute powers of two up to 100000
    static vector<int> pow2(100000+1, 1);
    for(int i = 1; i <= 100000; i++){
        pow2[i] = (pow2[i-1] << 1) % MOD;
    }

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> p(n), q(n);
        for(int &x : p) cin >> x;
        for(int &x : q) cin >> x;

        // posp[v] = index j where p[j]=v, similarly posq
        vector<int> posp(n), posq(n);
        for(int i = 0; i < n; i++){
            posp[p[i]] = i;
            posq[q[i]] = i;
        }

        // for each i, collect which values v become "eligible" at step i
        vector<vector<int>> become(n);
        for(int v = 0; v < n; v++){
            become[posp[v]].push_back(v);
            if(posq[v] != posp[v])
                become[posq[v]].push_back(v);
        }

        vector<bool> elig(n,false);
        int maxElig = -1;

        vector<int> r(n);
        for(int i = 0; i < n; i++){
            // mark newly eligible values
            for(int v : become[i]){
                if(!elig[v]){
                    elig[v] = true;
                    maxElig = max(maxElig, v);
                }
            }
            int vp = maxElig; 
            // we know vp>=0
            int bestMin = -1;

            // candidate 1: take j = posp[vp], k = i - j
            if(posp[vp] <= i){
                int j = posp[vp], k = i - j;
                // k>=0 automatically and k<=i
                bestMin = max(bestMin, q[k]);
            }
            // candidate 2: take k = posq[vp], j = i - k
            if(posq[vp] <= i){
                int k = posq[vp], j = i - k;
                bestMin = max(bestMin, p[j]);
            }
            // r[i] = 2^vp + 2^{bestMin} (mod)
            r[i] = add(pow2[vp], pow2[bestMin]);
        }

        // output
        for(int i = 0; i < n; i++){
            cout << r[i] << (i+1<n?' ':'\n');
        }
    }
    return 0;
}
