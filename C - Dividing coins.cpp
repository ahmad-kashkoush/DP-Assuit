//
// Created by ahmed-kashkoush on 3/1/23.
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
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
vector<int> v;
int dp[101][1010];
int n, total;
int DividingCoins(int i, int sum){
    // I need to obtain minimum possible sum From this problem
    if(i==n)
        return abs(2*sum-total);
    int &ret=dp[i][sum];
    if(ret!=-1)return ret;
    ret=0;
    int leave= DividingCoins(i+1, sum);
    int take= DividingCoins(i+1, sum+v[i]);
    return ret=min(take, leave);
}
void solve() {
   cin>>n;
    v=vector<int> (n);
    memset(dp, -1, sizeof(dp));
    total=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        total+=v[i];
    }
    cout<<DividingCoins(0, 0);

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
