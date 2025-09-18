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
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        string str;
        cin>>str;

        unordered_set<char> map;
        int result=0;
        for(int i=0; i<n; i++){
            if(map.find(str[i])==map.end()){
                result+=2;
                map.insert(str[i]);
            }else{
                result++;
            }
        }

        cout<<result<<"\n";
    }
}