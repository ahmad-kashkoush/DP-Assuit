//
// Created by ahmed-kashkoush on 2/27/23.
//
//والله يابني مانا عارف ادينا بنهبد
//كود بلا هدف, تكبييييير
// Problem Link -->
/**symbols
    @!  --> important and and write it down
*/
#include<bits/stdc++.h>

#define el '\n'
#define ll long long
#define reset(v, d) memset(v, d , sizeof(v))
#define all(s)  s.begin(), s.end()
#define cin(v)  for(auto &i:v)cin>>i
#define cout(v) for(auto i:v)cout<<i<<" "
#define weight first
#define price second
using namespace std;
void judge();void tc();

int n, g;
vector<pair<int, int>> v;
vector<vector<int>>dp;
ll rec(int i, int w){
    if(i==n)
        return 0;
    int &ret=dp[i][w];
    if(ret!=-1)return ret;
    if(w<v[i].weight)
        return ret=rec(i+1, w);
    return ret=max(rec(i+1, w), v[i].price+rec(i+1, w-v[i].weight));
}

void solve() {
        cin>>n;
        v=vector<pair<int, int>>(n);
        dp=vector<vector<int>> (n, vector<int>(50, -1));
        for(int i=0;i<n;i++)
            cin>>v[i].price>>v[i].weight;
        cin>>g;
        ll ans=0;
        for(int i=0;i<g;i++){
            int x; cin>>x;
            ans+=rec(0, x);
        }
        cout<<ans;


}

int main() {
    judge();
    tc();
//    solve();
    return 0;
}
void tc(){
    int t = 1;
      cin>>t;
    for (int tc = 1; tc <= t; tc++) {
        //cout<<"#tc"<< tc<<": ";
        solve();
        //    cout<<endl;
        cout<<el;
    }
}
void judge() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}