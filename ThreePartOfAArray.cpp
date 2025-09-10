// #include <bits/stdc++.h>
// using namespace std;

// #define f first
// #define s second
// #define pb push_back

// typedef long long int ll;
// typedef unsigned long long int ull;
// typedef pair<int,int> pii;
// typedef pair<ll,ll> pll;

// #define mod 1000000007
// #define INF 1000000000


// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin>>n;
//     vector<ll> v(n);
//     for(int i=0; i<n; i++) cin>>v[i];

//     ll l=0, r=n-1;
//     ll suml=0, sumr=0;
//     ll result;

//     while(l<r){
//         if(suml==sumr){
//             result=suml;
//             suml+=v[l];sumr+=v[r];
//             l++;r--;
//         }else{
//             if(suml<sumr){
//                 suml+=v[l];
//                 l++;
//             }else{
//                 sumr+=v[r];
//                 r--;
//             }
//         }
//     }

//     if(suml==sumr){
//         result=suml;
//     }

//     cout<<result<<"\n";
// }



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int i = 0, j = n+1;
	ll zi = 0, zj = 0, solidx = 0;
	while (i < j) {
		if (zi < zj)
			zi += a[++i];
		else if (zi > zj)
			zj += a[--j];
		else {
			solidx = i;
			zi += a[++i];
			zj += a[--j];
		}
	}
	
	cout << accumulate(a+1, a+solidx+1, 0ll); // here
}