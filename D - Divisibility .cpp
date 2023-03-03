//
// Created by ahmed-kashkoush on 3/3/23.
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

int n,k;
int arr[10001];
vector<vector<int>> dp;
int mod(int a, int b=k){
    return (a%b+b)%b;
}
bool Divisible(int i, int ele){
    if(i==n)
        return ele==0;
    int &ret=dp[i][ele];
    if(ret!=-1)return ret;
    ret=0;
    if(Divisible(i+1, mod(ele+arr[i])))return ret=true;
    if(Divisible(i+1, mod(ele-arr[i])))return ret=true;
    return ret=false;
}
void solve() {
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    dp=vector<vector<int>>(n+1, vector<int>(k+10, -1));
    cout<<(Divisible(0, 0)?"Divisible":"Not divisible");

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
