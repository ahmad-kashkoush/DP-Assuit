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
ll KnapsackRecursive(int i, int Rem) {
    if(i==n)
        return 0;
    ll &ret=dp[i][Rem];
    if(ret!=-1)return ret;
    ret=0;
    auto [w, value]=v[i];
    if(Rem<w)
        return ret=KnapsackRecursive(i+1, Rem);
    return ret=max(
            KnapsackRecursive(i+1, Rem),
            value+KnapsackRecursive(i+1, Rem-w)
               );

}
ll KnapsackIterative(){
    ll value[n+10][m+10];
    // value[index][weight]=value
    for(int i=0;i<=n;i++){
        auto [ww, vv]=v[i];
        for(int w=0;w<=m;w++){
            if(i==0 or w==0)
                value[i][w]=0;
            else if(ww>w)
                value[i][w]=value[i-1][w];
            else
                value[i][w]=max(value[i-1][w],vv+value[i-1][w-ww]);
        }
    }
    return value[n][m];
}
int main() {
    judge();
    cin>>n>>m;
    v.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i].first>>v[i].second;
    dp.resize(n+1, vector<ll> (m+1, -1));

//    cout<<KnapsackIterative();
    cout<<KnapsackRecursive(0, m);

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