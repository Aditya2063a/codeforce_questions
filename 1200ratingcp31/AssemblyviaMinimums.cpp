// #include <bits/stdc++.h>
// using namespace std;

// #define f first
// #define s second
// #define pb push_back

// typedef long long int ll;
// typedef unsigned long long int ull;
// typedef pair<int,int> pii;
// typedef pair<ll,ll> pll;

// #define mod 1000000007
// #define INF 1000000000

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int tt;
//     cin >> tt;
//     while (tt--) {
//         int n; cin>>n;
//         vector<int> a((n*(n-1))/2);
//         for(int i=0; i<(n*(n-1))/2; i++) cin>>a[i];

//         unordered_set<int> st;
//         vector<int> ans;
//         int mx=INT_MIN;
//         for(int i=0; i<(n*(n-1))/2; i++){
//             if(st.find(a[i])==st.end()){
//                 ans.pb(a[i]);
//                 st.insert(a[i]);
//                 mx=max(mx, a[i]);
//             }
//         }

//         for(int i=0; i<n-ans.size()+1; i++){
//             ans.pb(mx+i+1);
//         }

//         for(int i=0; i<ans.size(); i++){
//             cout<<ans[i]<<" ";
//         }cout<< "\n";
//     }
// }


#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        int m = n * (n - 1) / 2;
        vector<int64> b(m);
        for (int i = 0; i < m; ++i) cin >> b[i];

        sort(b.begin(), b.end());

        vector<int64> a;
        int idx = 0;
        for (int sz = n - 1; sz >= 1; --sz) {
            a.push_back(b[idx + sz - 1]);
            idx += sz;
        }
        a.push_back(1000000000LL);

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}
