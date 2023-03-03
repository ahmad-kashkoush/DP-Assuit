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
map<pair<int, string>, int> dp;
map<pair<int, string>, bool> vis;
bool isPalindrome(const string &j){
    string tmp;
    tmp=j;
//    cout<<j<<el;
    reverse(all(tmp));
    return tmp==j;
}
int NumberOfPalindromes(int i, string str){
        if(i==n)
            return 0;

        if(vis[make_pair(i, str)]==1)return dp[make_pair(i, str)];
        vis[make_pair(i, str)]=1;
        int k= isPalindrome(str);
        return dp[make_pair(i, str)]=k+ NumberOfPalindromes(i+1, str+s[i])+ NumberOfPalindromes(i+1, str);
}
void solve() {
      cin>>s;
      n=s.size();
      dp.clear();
      vis.clear();
      cout<<NumberOfPalindromes(0, "");
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
