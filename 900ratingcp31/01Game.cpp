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
        string str; cin>>str;
        int n=str.length();
        int z=0,o=0;
        for(int i=0; i<n; i++){
            str[i]=='1' ? o++ : z++;
        }   

        if(min(z,o)%2==0){
            cout<<"NET"<<"\n";
        }else{
            cout<<"DA"<<"\n";
        }
    }
}