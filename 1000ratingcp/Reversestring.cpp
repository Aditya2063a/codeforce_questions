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

    int n; cin>>n;
    string str; cin>>str;

    string s=str;
    sort(s.begin(), s.end());
    if(str==s){
        cout<<"NO"<<"\n";
    }else{
        int l=-1;
        for(int i=0; i<n-1; i++){
            if(str[i+1]-'a'<str[i]-'a'){
                l=i;
                break;
            }
        }

        cout<<"YES"<<"\n";
        cout<< l+1 << " " << l+2 << "\n";
    }

}