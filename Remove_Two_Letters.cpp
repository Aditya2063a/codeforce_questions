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

// string helper(string& str, int& index, int& n){
//     string s="";

//     for(int i=0; i<n; i++){
//         if(i==index || i==index+1){
//             continue;
//         }else{
//             s+=str[i];
//         }
//     }

//     return s;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     cin>>tt;
//     while(tt--){
//         int n;
//         cin>>n;
//         string str;
//         cin>>str;
//         unordered_set<string> st;

//         for(int i=0; i<n-1; i++){
//             st.insert(helper(str, i, n));
//         }

//         cout<< st.size() << "\n";
//     }
    
//     return 0;
// }


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = n - 1;
    for (int i = 1; i + 1 < n; ++i) {
        if (s[i - 1] == s[i + 1]) {
            res--;
        }
    }
    cout << res << '\n';
}

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}