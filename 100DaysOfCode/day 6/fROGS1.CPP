//JAI MATA DI
//JAI SHREE RAM
 
#include <bits/stdc++.h>
using namespace std;
 
#define deb(x) cout << #x << " " << x <<endl;
 
#define fo(i, n)  for (auto i = 0; i < n; i++)
typedef long long int ll;
 
const ll INF = -10;
#define pb push_back
typedef vector<int> vi;
typedef vector<long long> vll;
 
ll solve(int curr, vi h, vll &dp) {
 
    if (curr == 1) return dp[curr]= 0; 
 
    if (curr == 2){
        return dp[curr]=abs(h[curr] - h[curr-1]);
    }
 
    if (dp[curr] != INF) return dp[curr];
 
    return dp[curr] = min(  solve(curr-1, h, dp) + abs(  h[curr] - h[curr-1]  ), 
                solve(curr-2, h, dp) + abs(  h[curr-2] - h[curr]  ) );
}
 
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
   
    int n; cin >> n; 
    vi h(n+1); 
 
    fo(i, n) cin>>h[n-i];
 
    vll dp(n+1, INF);
    dp[1]=0; 
 
    cout << solve(n, h, dp);
 
}