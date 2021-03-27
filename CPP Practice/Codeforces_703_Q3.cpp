// https://codeforces.com/contest/1492/problem/C
// LINK TO THE SUM ⬆⬆⬆⬆⬆⬆⬆
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
map<char,vector<int>> mp;


void solve() {
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    for(int i=0;i<n;i++){
        mp[s[i]].push_back(i);
    }

    int mini[m];
    int maxi[m];
    int ans=0;
    
    int abhi_min = -1;
    for(int i =0;i<m;i++){
        int indx= upper_bound(mp[t[i]].begin(),mp[t[i]].end(),abhi_min)-mp[t[i]].begin();
        abhi_min = mp[t[i]][indx];
        mini[i]=abhi_min;
    }

    for(auto &x:mp){
        for (auto &y:x.second){
            y=-y;
        }
        sort(x.second.begin(),x.second.end());
    }

    int abhi_max=-n-1;
    for(int i=m-1;i>=0;i--){
        int x=upper_bound(mp[t[i]].begin(),mp[t[i]].end(),abhi_max)-mp[t[i]].begin();
        abhi_max=mp[t[i]][x];
        maxi[i]=-abhi_max;
    }
    for(int i=1;i<m;i++){
        ans=max(ans,maxi[i]-mini[i-1]);
    }
    cout<<ans;
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}