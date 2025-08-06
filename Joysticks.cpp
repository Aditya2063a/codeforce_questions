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

    int a1,a2;
    cin>>a1>>a2;

    int result=0;

    while(a1>0 && a2>0){
        

        if(a1<a2){
            if(a1+1<100){
                a1+=1;
            }
            a2-=2;
        }else if(a1>a2){
            if(a2+1<100){
                a2+=1;
            }
            a1-=2;
        }else{
            if(a1==1){
                break;
            }else{
                a1+=1;
                a2-=2;
            }
        }

        result++;
    }

    cout<< result << "\n";

    return 0;
}