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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int a,b,c;
        cin>>a>>b>>c;

        if(a>b){
            cout<<"First"<<"\n";
        }else if(b>a){
            cout<<"Second"<<"\n";
        }else if(a==b){
            if(c%2!=0){
                cout<<"First"<<"\n";
            }else{
                cout<<"Second"<<"\n";
            }
        }
    }
}