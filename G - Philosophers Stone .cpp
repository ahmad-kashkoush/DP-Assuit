//
// Created by ahmed-kashkoush on 3/2/23.
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
using namespace std;
void judge();void tc();
const int mod = 1e9 + 7, OO = 2 * 1e9;
const double pi = 3.1415926535897932384;
int dx[]={1, 1, 1};
int dy[3]={-1, 0, 1};
int n, m;
vector<vector<ll>> v, dp;
ll rec(int i, int j){
    if(i<0 or i>=n or j<0 or j>=m)
        return 0;
    ll &ret=dp[i][j];
    if(ret!=-1)return ret;
    ret=0;
    for(int k=0;k<3;k++)
        ret=max(ret, v[i][j]+rec(i+1, j+dy[k]));
    return ret;

}
void solve() {
        cin>>n>>m;
        v=vector<vector<ll>> (n, vector<ll>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin>>v[i][j];
        }
        ll ans=0;
        dp = vector<vector<ll>>(n, vector<ll>(m, -1));
        for(int i=0;i<m;i++) {
            ans = max(ans, rec(0, i));
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