#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef unsigned long long int ull;
typedef pair<int,int> pii;

#define mod 1000000007
#define INF 1000000000
using int64 = long long;
using i128 = __int128_t;

long long sumDigits(long long n) {
    if (n <= 0) return 0;
    long long res = 0;
    long long p = 1;
    while (p <= n) {
        long long high = n / (p * 10);
        long long cur = (n / p) % 10;
        long long low = n % p;
        res += high * 45 * p;
        res += (cur * (cur - 1) / 2) * p;
        res += cur * (low + 1);
        p *= 10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        long long k; cin >> k;
        long long res = 0;
        long long d = 1;
        long long start = 1;
        while (true) {
            long long cnt = 9 * (long long)pow(10, d-1); 
            long long blockLen = cnt * d;
            if (k > blockLen) {
                long long end = start + cnt - 1;
                res += sumDigits(end) - sumDigits(start - 1);
                k -= blockLen;
                start = end + 1;
                d++;
            } else {
                long long fullNumbers = k / d;
                long long extraDigits = k % d;
                if (fullNumbers > 0) {
                    long long end = start + fullNumbers - 1;
                    res += sumDigits(end) - sumDigits(start - 1);
                    start = end + 1;
                }
                if (extraDigits > 0) {
                    string s = to_string(start);
                    for (int i = 0; i < extraDigits; i++) {
                        res += s[i] - '0';
                    }
                }
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
