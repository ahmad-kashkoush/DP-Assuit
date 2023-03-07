/*
 Mistake--> When there's a division , see if you can make it multiplication
 
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
const int mod = 1e9 + 7, OO = 2 * 1e9;
const double pi = 3.1415926535897932384;
int n, k;
vector<int> a, b;
int dp[101][(int)5e5];
int MxTaste(int i, int diff){

    if(i==n){
        if(diff==0)return 0;
        else return -INT32_MAX;
    }
    int &ret=dp[i][diff+(int)1e4];
    if(~ret)return ret;
    return ret=max(MxTaste(i+1, diff),MxTaste(i+1, diff+a[i]-b[i]*k)+a[i]);

    return ret;
}
int main() {
    judge();
    cin>>n>>k;
    a=b=vector<int>(n, -1);
    reset(dp, -1);
    cin(a);cin(b);
    cout<<(MxTaste(0, 0)>0? MxTaste(0, 0):-1);
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
