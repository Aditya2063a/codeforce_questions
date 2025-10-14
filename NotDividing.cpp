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
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for(int test_number = 0; test_number < t; test_number++){
		int n; cin >> n;
		vector <int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			if(a[i] == 1){
				a[i]++;
			}
		}
		for(int i = 1; i < n; i++){
			if(a[i] % a[i - 1] == 0){
				a[i]++;
			}
		}
		for(auto i : a){
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;

}