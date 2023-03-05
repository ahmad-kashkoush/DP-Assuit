//
// Created by ahmed-kashkoush on 3/5/23.
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
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
string s;
int n;
int dp[1001][1001];
int StringToPalindrome(int i, int j){
    if(i>=j)
        return 0;
    int &ret=dp[i][j];
    if(~ret)return ret;
    if(s[i]==s[j])
        return ret= StringToPalindrome(i+1, j-1);
    ret=1+ StringToPalindrome(i+1, j-1);//change
    ret=min(ret, 1+ StringToPalindrome(i, j-1));//removing From the end
    ret=min(ret, 1+ StringToPalindrome(i+1, j));//removing from Front;
    return ret;
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
        cin>>s;
        n=s.size();
        memset(dp, -1, sizeof(dp));
        cout<<"Case "<<tc<<": "<<StringToPalindrome(0, n-1);
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
