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

//         int r=0;
//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 if(vec[j]>=(j-i+1)){
//                     r++;
//                 }else{
//                     break;
//                 }
//             }
//         }

//         cout<<r<<"\n";
//     }
// }


#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if(!(cin >> T)) return 0;
    while(T--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        vector<int> val(n);
        for(int i=0;i<n;i++) val[i] = (i+1) - a[i] + 1;

        long long ans = 0;
        int r = -1; 
        for(int l = 1; l <= n; ++l){ // l is 1-based
            while(r + 1 < n && val[r + 1] <= l) ++r;
            if(r >= l - 1) ans += (long long)(r - (l - 1) + 1); // = r - l + 2
        }

        cout << ans << '\n';
    }
    return 0;
}
