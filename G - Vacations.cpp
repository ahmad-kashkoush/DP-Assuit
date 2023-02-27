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


int main() {
    judge();
    int n; cin>>n;
    int dp[n+1][4];
    dp[0][1]=dp[0][2]=dp[0][0]=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        dp[i][0]=min({dp[i-1][0], dp[i-1][1], dp[i-1][2]})+1;
        //take the day off and store its values
        dp[i][1]=101;
        dp[i][2]=101;
        if(x==2 or x==3)
            dp[i][1]=min(dp[i-1][2], dp[i-1][0]);
        if(x==1 or x==3)
            dp[i][2]=min(dp[i-1][1], dp[i-1][0]);
    }
    cout<<min({dp[n][1], dp[n][2], dp[n][0]});
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