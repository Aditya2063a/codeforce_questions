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

//     int n; cin>>n; int sum=0;
//     vector<int> a(n); unordered_map<int,int> mp;
//     for(int i=0; i<n; i++){
//         cin>>a[i];
//         sum+=a[i];
//         mp[a[i]]++;
//     }

//     vector<int> result;
//     for(int i=0; i<n; i++){
//         int k=sum-a[i];
//         if(k%2==0 and mp.count(k/2)>1){
//             result.pb(i+1);
//         }
//     }

//     cout<< result.size() << "\n";
//     for(int i=0; i<result.size(); i++){
//         cout<< result[i] << " ";
//     }cout<<"\n";


// }


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, int> freq;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        freq[a[i]]++;
    }

    vector<int> result;

    for (int i = 0; i < n; i++) {
        ll rem_sum = sum - a[i];
        if (rem_sum % 2 != 0) continue;

        ll target = rem_sum / 2;
        freq[a[i]]--;

        if (freq[target] > 0) {
            result.push_back(i + 1);
        }

        freq[a[i]]++;
    }

    cout << result.size() << "\n";
    for (int idx : result) cout << idx << " ";
    cout << "\n";
}
