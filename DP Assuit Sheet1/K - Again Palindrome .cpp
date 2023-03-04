// Created by ahmed-kashkoush on 3/3/23.
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
string s;int n;
vector<vector<ll>> dp;

ll NumberOfPalindromes(int i, int j){
//    cout<<s.substr(i, j-i+1)<<el;
    if(i==j)return 1;
    if(i+1==j)return 2+(s[i]==s[j]);
    ll &ans=dp[i][j];
    if(ans!=-1)return ans;
    ans=0;
    if(s[i]==s[j])
         ans+=1+ NumberOfPalindromes(i+1, j-1);
    ans+= NumberOfPalindromes(i+1, j);
    ans+= NumberOfPalindromes(i, j-1);
    ans-= NumberOfPalindromes(i+1, j-1);
    return ans;


}
void solve() {
      cin>>s;
      n=s.size();
      dp=vector<vector<ll>>(n+10, vector<ll>(n+10,-1 ));
      cout<<NumberOfPalindromes(0, n-1);
      s.clear();

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
