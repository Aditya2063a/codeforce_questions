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

// int helper(string& str, int& index, int& n){
//     int l=0,r=0;

//     int i=index, j=index;
//     while(i-1>=0){
//         if(str[i]=='v' && str[i-1]=='v'){
//             l++;
//         }
//         i--;
//     }

//     while(j+1<n){
//         if(str[j]=='v' && str[j+1]=='v'){
//             r++;
//         }
//         j++;
//     }

//     return l*r;
// }

// int solve(string& str){
//     int n=str.length();
//     int res = 0;

//     for(int i=0; i<n; i++){
//         if(str[i]=='o'){
//             res += helper(str, i, n);
//         }
//     }

//     return res;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     string str;
//     cin>>str;

//     int result = solve(str);

//     cout<< result << "\n";
//     return 0;
// }


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    cin >> str;
    int n = str.size();
    
    vector<int> prefix(n, 0);
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1];
        if(str[i] == 'v' && str[i-1] == 'v'){
            prefix[i]++;
        }
    }
    
    vector<int> suffix(n, 0);
    for(int i = n - 2; i >= 0; i--){
        suffix[i] = suffix[i+1];
        if(str[i] == 'v' && str[i+1] == 'v'){
            suffix[i]++;
        }
    }
    
    long long result = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == 'o'){
            result += (long long)prefix[i] * suffix[i];
        }
    }
    
    cout << result << "\n";
    return 0;
}
