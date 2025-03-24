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
    cin.tie(nullptr); 
    cout.tie(nullptr);

	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;

	int i=0, ans=0;
	while(i<n)
	if(s[i]!=t[i])
	{
		if(i+1<n&&s[i+1]!=t[i+1]&&s[i]!=s[i+1])
		{
			ans++;
			i+=2;
		}
		else
		{
			ans++;
			i++;
		}
	}else{
	    i++;
    }
    
	cout<<ans<<endl;
	return 0;
}