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

// int main(){
//     cin.tie(0);
//     ios_base::sync_with_stdio(false);

//     int n;
//     cin >> n;
//     vector<pii> vec(n);
//     for(int i=0; i<n; i++){
//         cin >> vec[i].f >> vec[i].s;
//     }

//     sort(vec.begin(), vec.end());

//     int ans = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(vec[i].f==vec[j].f || vec[i].s==vec[j].s){
//                 ans++;
//             }
//         }
//     }

//     cout << ans << "\n";
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int>> points(n);
    for (int i=0;i<n;i++) {
        cin >> points[i].first >> points[i].second;
    }

    unordered_map<int,ll> countX;
    unordered_map<int,ll> countY;
    map<pair<int,int>, ll> countXY;

    for (auto &p : points) {
        countX[p.first]++;
        countY[p.second]++;
        countXY[p]++;
    }

    auto comb2 = [](ll k) -> ll {
        return k*(k-1)/2;
    };

    ll ans = 0;
    for (auto &kv : countX) ans += comb2(kv.second);
    for (auto &kv : countY) ans += comb2(kv.second);
    for (auto &kv : countXY) ans -= comb2(kv.second); 

    cout << ans << "\n";
    return 0;
}
