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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, k, x;
        cin >> n >> k >> x;

        if (x != 1) {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++) cout << 1 << " ";
            cout << "\n";
        } 
        else if (k == 1) {
            cout << "NO\n";
        } 
        else if (k == 2) {
            if (n % 2 == 1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                cout << n / 2 << "\n";
                for (int i = 0; i < n / 2; i++) cout << 2 << " ";
                cout << "\n";
            }
        } 
        else {
            cout << "YES\n";
            if (n % 2 == 0) {
                cout << n / 2 << "\n";
                for (int i = 0; i < n / 2; i++) cout << 2 << " ";
                cout << "\n";
            } else {
                cout << (n - 3) / 2 + 1 << "\n"; 
                cout << 3 << " ";
                for (int i = 0; i < (n - 3) / 2; i++) cout << 2 << " ";
                cout << "\n";
            }
        }
    }
}