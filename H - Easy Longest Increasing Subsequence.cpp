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
int n;
int arr[25];
int dp[25];
int rec(int i){
    if(i==n)
        return 0;
    int &ret=dp[i];
    if(ret!=-1)return ret;
    ret=0;
    for(int j=i+1;j<n;j++){
        if(arr[j]>arr[i])
            ret=max(ret, rec(j));
    }
    ret++;
    return ret;
}
int LISIterative(){
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    if(n==1)return dp[0];
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
           if(arr[i]>arr[j])
               dp[i]=max(dp[i], dp[j]+1);
        }
    }

    return *max_element(dp, dp+n);
}
void solve() {
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ans=0;
//    for(int i=0;i<n;i++)
//        ans=max(rec(i), ans);
    ans=LISIterative();
    cout<<ans;


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
