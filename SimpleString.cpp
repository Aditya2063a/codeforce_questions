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
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != s[i - 1] && (i + 1 == n || c != s[i + 1])) {
                    s[i] = c;
                    break;
                }
            }
        }
    }

    cout << s << "\n";
    return 0;
}