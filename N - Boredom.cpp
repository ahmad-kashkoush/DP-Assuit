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
using namespace std;
void judge();
ll v[100005];
ll dp[100005];
int n;
ll Max=0;
ll rec(int i){
    if(i>Max)
        return 0;
    if(dp[i]!=-1)return dp[i];
    dp[i]=0;
    return dp[i]=max(
            i*v[i]+rec(i+2),
            rec(i+1)
            );

}
ll Iterative(int mn){
    dp[mn]=mn*v[mn];
    mn++;
    dp[mn]=max((mn*v[mn]), dp[mn-1]);
    mn++;
    for(int i=mn;i<=Max;i++){
        dp[i]=max(dp[i-1], i*v[i]+dp[i-2]);
    }
    return dp[Max];
}
ll IterativeOptimized(int mn){
   ll a=mn*v[mn];
    mn++;
    ll b=max((mn*v[mn]), a);
    mn++;
    ll c=b;
    for(int i=mn;i<=Max;i++){
        c=max(b, i*v[i]+a);
        a=b, b=c;
    }
    return c;
}
void solve() {
   cin>>n;
   memset(dp, -1, sizeof(dp));
   ll mn=INT_MAX, mx=0;
   for(int i=0;i<n;i++){
      ll x; cin>>x;
       v[x]++;
       mx=max(x, mx);
       mn=min(mn, x);
   }
   Max=mx;
//   cout<<Iterative(mn);
//   cout<<rec(mn);
   cout<<IterativeOptimized(mn);

}

int main() {
    judge();

    solve();
    return 0;
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
