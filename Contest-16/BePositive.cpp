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
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }

        int zero=0, minus=0;
        for(int i=0; i<n; i++){
            if(vec[i]==-1) minus++;
            else if(vec[i] == 0) zero++;
        }

        int result=0;
        result+=zero;
        if(minus%2!=0){
            result+=2;
        }

        cout<<result<<"\n";
    }
}