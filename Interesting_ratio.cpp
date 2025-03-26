#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    if(n >= 0) isPrime[0] = false;
    if(n >= 1) isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if(isPrime[i]){
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    vector<int> testCases(t);
    int max_n = 0;
    for (int i = 0; i < t; i++){
        cin >> testCases[i];
        max_n = max(max_n, testCases[i]);
    }
    
    vector<bool> isPrime = sieve(max_n);
    vector<int> primes;
    for (int i = 2; i <= max_n; i++){
        if(isPrime[i])
            primes.push_back(i);
    }
    
    // Process each test case.
    for (int n : testCases) {
        ll res = 0;
        // For every prime p <= n, add floor(n / p)
        for (int p : primes) {
            if(p > n)
                break;
            res += n / p;
        }
        cout << res << "\n";
    }
    
    return 0;
}
