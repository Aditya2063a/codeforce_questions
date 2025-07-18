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

    int n;
    cin>>n;

    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    vector<int> prefix(n, 0), suffix(n, 0);
    int sum=0; 
    for(int i=0; i<n; i++){
        sum+=vec[i];
        prefix[i]=sum;
    }
    sum=0;
    for(int i=n-1; i>=0; i--){
        sum+=vec[i];
        suffix[i]=sum;
    }

    int result=0;
    for(int i=0; i<n-1; i++){
        if(prefix[i]==suffix[i+1]){
            result++;
        }
    }

    cout<< result << '\n';

    return 0;
}
