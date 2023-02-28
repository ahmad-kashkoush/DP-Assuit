//
// Created by ahmed-kashkoush on 2/28/23.
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
#define value  second
using namespace std;
void judge();
int n,m;
vector<pair<int, int>> v;
vector<vector<ll>> dp;

// You need to maximize value
ll KnapsackRecursive(ll i,ll curValue) {
    if(i>n)
        return curValue==0?0:INT_MAX;
    ll &ret=dp[i][curValue];
    if(ret!=-1)return ret;

    auto [w, value]=v[i];
    if(curValue<value)
        return ret= KnapsackRecursive(i+1, curValue);
    return ret=min(KnapsackRecursive(i+1, curValue),
                   w+ KnapsackRecursive(i+1, curValue-value));
}
ll Ans(ll mx){
    for(ll i=mx;i>=0;i--){
        if(KnapsackRecursive(1, i)<=m)
            return i;
// dp[i][value]=minimum weight that we can obtain
    }
    return 0;
}
ll Knapsack2Iterative(ll mx){
/*
 Base case
 1. dp[1][0]=0 dp[i][0]=0;
 2. dp[0][anyvalue]=int_max     DP[1]=min(dp[0][j], ---)
 3. dp[i][j]=min(dp[i-1][j], weight+dp[i-1][j-value];
 maximum weight dp[n][value]<=m---> value
 * */
    int ans=0;
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int j=1;j<=mx;j++)
        dp[0][j]=INT_MAX;


    for(int i=1;i<=n;i++){
        for(int j=1;j<=mx;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=v[i].value)
                dp[i][j]=min(dp[i][j], v[i].weight+dp[i-1][j-v[i].value]);
        }

    }
    for(int i=mx;i>=0;i--){
        if(dp[n][i]<=m)
            return i;
    }


}


int main() {
    judge();
    cin>>n>>m;
    v.resize(n+1);
    ll Max_value=0;
    for(int i=1;i<=n;i++) {
        cin >> v[i].first >> v[i].second;
        Max_value+=v[i].second;
    }
    dp.resize(n+1, vector<ll> (Max_value+10, INT_MAX));
    // reset dp to -1 for recursive solution
//        cout<<Ans(Max_value);
    cout<<Knapsack2Iterative(Max_value);
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
