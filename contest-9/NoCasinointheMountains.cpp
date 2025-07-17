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
//         int n,k;
//         cin>>n>>k;
//         vector<int> vec(n);

//         for(int i=0; i<n; i++){
//             cin>>vec[i];
//         }

//         int result=0;

//         for(int i=0; i<n-k; i++){
//             bool possible=true;
//             for(int j=i; j<=i+k-1; j++){
//                 if(vec[j]==1){
//                     possible=false;
//                 }
//             }

//             if(possible){
//                 result++;
//                 i+=1;
//             }
//         }


//         cout<<result<<"\n";
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        int count = 0;
        int i = 0;

        while (i <= n - k) {
            bool canHike = true;

            // Check next k days
            for (int j = 0; j < k; ++j) {
                if (a[i + j] == 1) {
                    canHike = false;
                    break;
                }
            }

            if (canHike) {
                count++;
                i += k + 1; // skip k days of hike + 1 rest day
            } else {
                i++; // try next day
            }
        }

        cout << count << "\n";
    }

    return 0;
}
