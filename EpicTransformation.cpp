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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        unordered_map<ll, ll> mp;
        for(int i=0; i<n; i++){
            mp[a[i]]++;
        }

        priority_queue<pll> pq;
        for(auto it: mp){
            pq.push({it.s, it.f});
        }

        while(pq.size() > 1){
            pll top1 = pq.top();
            pq.pop();
            pll top2 = pq.top();
            pq.pop();

            if(top1.f > 1){
                pq.push({top1.f - 1, top1.s});
            }
            if(top2.f > 1){
                pq.push({top2.f - 1, top2.s});
            }
        }
        if(pq.empty()){
            cout << 0 << "\n";
        } else {
            cout << pq.top().f << "\n";
        }

    }


    return 0;
}