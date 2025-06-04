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


void print(vector<pii>& v){
    int n=v.size();
    for(int i=0; i<n; i++){
        cout<< v[i].f << ' ' << v[i].s << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int n,k;
    cin>>n>>k;

    if((n-1)%2==0 && (n-1)/2<k){
        cout<< -1 << "\n";
    }else if((n-1)%2!=0 && (n-1)/2+1<=k){
        cout<< -1 <<"\n";
    }else{
        int total_matches = n*k;
        int i=1;
        vector<pii> vec;

        while(i<n+1){
            int m=i+1;
            for(int j=0; j<k; j++){
                if(m>n){
                    m=1;
                }
                vec.pb(make_pair(i,m));
                m++;
            }
            i++;
        }

        cout<< total_matches << "\n";
        print(vec);
    }
}