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
    cin>> tt;
    while(tt--){
        int n;
        cin >> n;
        string a;
        cin>>a;
        int m;
        cin >> m;
        string b, c;
        cin >> b >> c;
        int start=0;
        for(int i=0; i<m; i++){
            if(c[i]=='D'){
                a=a+b[start];
            }else{
                a = b[start]+a;
            }
            start++;
        }


        cout<<a<<endl;
    }


    return 0;
}