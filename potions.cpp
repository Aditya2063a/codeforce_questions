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

void print(vector<int>& b){
    for(int i=0; i<b.size(); i++){
        cout<<b[i]<< ' ';
    }cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    int sum=0, ans=0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x<0){
            v.pb(x);
        }else{
            sum+=x;
            if(x>0){
                ans++;
            }
        }
    }


    for(int i=0; i<v.size(); i++){
        if(sum+v[i]>0 || sum+v[i]==0){
            sum+=v[i];
            ans++;
        }else{
            break;
        }
    }


    cout<<ans<<endl;

    return 0;
}