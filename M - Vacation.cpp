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
int dp[102][102];
int LCSRecursive(int i, int j, const string &a, const string &b){
    if(i==a.size()|| j==b.size())
        return 0;
    int &ret=dp[i][j];
    if(ret!=-1)return ret;
    ret=0;
    if(a[i]==b[j])
        return ret=1+ LCSRecursive(i+1, j+1, a, b);
    ret=max(ret, LCSRecursive(i+1, j, a, b));
    ret=max(ret, LCSRecursive(i, j+1, a, b));
    return ret;
}

int main() {
    judge();
    int cnt=0;
    while(1){
        string a;cin>>a;
        if(a=="#")return 0;
        cnt++;
        string b;cin>>b;
        memset(dp, -1, sizeof(dp));
        int ans= LCSRecursive(0, 0,a, b);
        cout<<"Case #"<<cnt<<": you can visit at most " <<ans<< " cities.";
        cout<<el;
    }
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