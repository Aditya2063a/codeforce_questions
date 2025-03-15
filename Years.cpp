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

// static bool compare(pair<int,int>& a, pair<int,int>& b){
//     if(a.first == b.first)
//         return a.second < b.second;
//     return a.first < b.first;
// }

// void print(deque<int>& b){
//     for(int i=0; i<b.size(); i++){
//         cout<<b[i]<< ' ';
//     }cout<<endl;
// }

// void solve(vector<pii>& vec, vector<pii>& result){
//     deque<int> dq;
//     int pop=0, y=0;
//     int i = 0;
//     while(i < vec.size()){
//         int year = vec[i].first;
        
//         while(!dq.empty() && dq.front() <= year){
//             dq.pop_front();
//         }

//         while(i < vec.size() && vec[i].first == year){
//             dq.push_back(vec[i].second);
//             i++;
//         }
//         sort(dq.begin(), dq.end());
//         // print(dq);
//         if(pop < dq.size()){
//             pop = dq.size();
//             y = year;
//         }
//     }
//     result.pb({y, pop});
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     vector<pii> vec;
//     for(int i=0; i<n; i++){
//         int a, b;
//         cin >> a >> b;
//         vec.pb({a, b});
//     }
//     sort(vec.begin(), vec.end(), compare);

//     vector<pii> result;
//     solve(vec, result);

//     cout << result[0].first << " " << result[0].second << '\n';
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<pair<long long, int>> events;
    events.reserve(2*n);
    
    for (int i = 0; i < n; i++){
        long long b, d;
        cin >> b >> d;
        events.push_back({b, 1});   
        events.push_back({d, -1});  
    }
    
    sort(events.begin(), events.end());
    
    long long current = 0, maxCount = 0, year = 0;
    int i = 0;
    
    while(i < events.size()){
        long long currentYear = events[i].first;
        long long delta = 0;
        while(i < events.size() && events[i].first == currentYear){
            delta += events[i].second;
            i++;
        }
        current += delta;
        if(current > maxCount){
            maxCount = current;
            year = currentYear;
        }
    }
    
    cout << year << " " << maxCount << "\n";
    return 0;
}
