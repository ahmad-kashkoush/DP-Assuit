//
// Created by ahmed-kashkoush on 2/25/23.
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


void solve() {
    int n; cin>>n;
    vector<int> x(n+10, 0), height(n+10, 0);
    for(int i=0;i<n;i++)
        cin>>x[i]>>height[i];
    if(n<=2)
        cout << n;
    else{
       int ans=2;
       int prev=x[0];
        for(int i=1;i<n-1;i++){
            // fall left
            if(x[i]-height[i]>prev){
                    prev=x[i];
                    ans++;
            }else if(x[i]+height[i]<x[i+1]){
                prev=x[i]+height[i];
                ans++;
            }else
                prev=x[i];
        }
        cout<<ans;
    }



}

int main() {
    judge();
    solve();
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
