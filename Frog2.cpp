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


void solve() {
   int n, m; cin>>n>>m;
   vector<int> v(n+10, 0), dp(n+10, 0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1]+abs(v[i]-v[i-1]);
        for(int j=i-2;j>=i-m and j>=0 ;j--){
            dp[i]=min(dp[j]+abs(v[i]-v[j]),
                      dp[i]);
        }
    }
    cout<<dp[n-1];
}

int main() {
    judge();
//    tc();
    solve();
    return 0;
}
void tc(){
    int t = 1;
    //  cin>>t;
    for (int tc = 1; tc <= t; tc++) {
        //cout<<"#tc"<< tc<<": ";
        solve();
        //    cout<<endl;
        //cout<<el;
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