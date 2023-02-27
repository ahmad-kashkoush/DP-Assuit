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
void judge();void tc();
const int mod = 1e9 + 7, OO = 2 * 1e9;
const double pi = 3.1415926535897932384;
int *a, *b, *c;
ll dp[100005][5];
int n;
ll Rec(int i, int choice){
    if(i==n)
        return 0;
    ll &ans=dp[i][choice];
    if(ans!=-1)return ans;
    ans=0;
    if(choice!=0)
        ans=max(ans, a[i]+Rec(i+1, 0));
    if(choice!=1)
        ans=max(ans, b[i]+Rec(i+1, 1));
    if(choice!=2)
        ans=max(ans, c[i]+Rec(i+1, 2));
    return ans;

}
int Iterative(){
    memset(dp, 0, sizeof(dp));
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];
    for(int i=1;i<n;i++){
      for(int j=0;j<3;j++)
          dp[i][j]=dp[i-1][j];
      dp[i][0]=a[i]+max(dp[i-1][1], dp[i-1][2]);
      dp[i][1]=b[i]+max(dp[i-1][0], dp[i-1][2]);
      dp[i][2]=c[i]+max(dp[i-1][1], dp[i-1][0]);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++)
            ans=max(ans, dp[i][j]);
    }
    return ans;

}
void solve() {
        cin>>n;
        a=new int[n+1];
        b=new int[n+1];
        c=new int[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i]>>b[i]>>c[i];
//        memset(dp, -1, sizeof(dp));
//        cout<<Rec(0, 4);
            cout<<Iterative();

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