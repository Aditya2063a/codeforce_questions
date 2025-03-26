#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 998244353;
 
// fast modular exponentiation
long long modExp(long long base, long long exp) {
    long long res = 1;
    while(exp){
        if(exp & 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    
    int maxN = 200000;
    vector<long long> pow2(maxN+1), inv2(maxN+1);
    pow2[0] = 1;
    for (int i = 1; i <= maxN; i++){
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }
    for (int i = 0; i <= maxN; i++){
        inv2[i] = modExp(pow2[i], MOD-2); // Fermat's little theorem
    }
    
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        // We want to count beautiful subsequences of the form [1, (nonempty sequence of 2's), 3].
        long long ans = 0;
        long long S = 0;     // sum of weights for each 1 seen so far (each weight = inv2[count2] at time of encounter)
        long long count1 = 0; // count of ones seen so far
        int count2 = 0;      // count of 2's seen so far (used as exponent)
 
        // Process array in order.
        for (int i = 0; i < n; i++){
            if(a[i] == 1){
                // For a 1, record its weight (1/2^(# of 2's seen so far))
                S = (S + inv2[count2]) % MOD;
                count1++;
            } else if(a[i] == 3){
                // For a 3, every earlier 1 contributes:
                //   2^(current count2) * (its weight) - 1.
                // Summing over all earlier 1's: contribution = 2^(count2) * S - count1.
                long long term = ( (pow2[count2] * S) % MOD - count1 ) % MOD;
                if(term < 0) term += MOD;
                ans = (ans + term) % MOD;
            } else if(a[i] == 2){
                // Increase the count of 2's
                count2++;
            }
        }
 
        cout << ans % MOD << "\n";
    }
    
    return 0;
}
