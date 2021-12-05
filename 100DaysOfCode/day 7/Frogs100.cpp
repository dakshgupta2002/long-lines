//JAI MATA DI
//JAI SHREE RAM

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x <<endl;
#define fo(i, n)  for (auto i = 0; i < n; i++)
typedef long long int ll;



#define pb push_back
typedef vector<int> vi;
typedef vector<long long> vll;
const ll INF = 1000000000000000000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   
    ll n, k; cin >> n >> k; 

    vll h(1); 
    fo(i, n){  //index 1 to n heights
        ll h1; cin>>h1; 
        h.pb(h1);
    }

    vll dp(n+1, INF); 
    dp[n] = 0; 

    for (int curr=n-1; curr>=1; curr--){
        //set dp[curr]

        ll i=curr+1; 
        while(i<=n && i<=curr+k){

            dp[curr] = min(   dp[curr],   ( dp[i] + abs(h[i]-h[curr]))   );
            i++;
        }

    }

    cout << dp[1] << endl;

}




