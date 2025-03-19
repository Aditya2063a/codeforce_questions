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


// int solve(vector<int>& vec){
//     int result=0, n = vec.size();

//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(vec[j]-vec[i]==j-i){
//                 result++;
//             }
//         }
//     }

//     return result;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     cin>>tt;
//     while(tt--){
//         int n;
//         cin>>n;
//         vector<int> vec(n);
//         for(int i=0; i<n; i++){
//             cin>>vec[i];
//         }

//         int result = solve(vec);

//         cout<< result << "\n";
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  map<int, int> a;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x -= i;
    res += a[x];
    a[x]++;
  }
  cout << res << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}