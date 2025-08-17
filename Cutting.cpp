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

    int n,b;
    cin>>n>>b;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int cnte=0,cnto=0;
    vector<int> store;
    for(int i=0;i<n; i++){
        if(v[i]%2==0){//even
            cnte++;
        }else{
            cnto++;
        }

        if(i!=n-1 && cnte==cnto){
            store.push_back(abs(v[i]-v[i+1]));
        }
    }

    int result=0;
    sort(store.begin(), store.end());
    for(int i=0; i<store.size(); i++){
        if(store[i]<=b){
            result++;
            b-=store[i];
        }else{
            break;
        }
    }

    cout<<result<<"\n";

    return 0;
}