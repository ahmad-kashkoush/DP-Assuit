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

    }
    return 0;
}
ll Knapsack2Iterative(ll mx){
    int ans=0;
    for(int i=0;i<=n;i++){
        auto [weight, value]=v[i];
        for(int j=0;j<=mx;j++){
            if(i==0 or j==0)
                dp[i][j]=0;
            else if(j-value<0)//can't take this value
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=min(dp[i-1][j], weight+dp[i-1][j-value]);

        }

    }
    return ans;
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
        dp.resize(n+1, vector<ll> (Max_value+1, INT_MAX));
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
