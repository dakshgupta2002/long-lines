//JAI MATA DI
//JAI SHREE RAM

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x <<endl;
#define sum(a) accumulate(a.begin(), a.end(), 0);

#define fo(i, n)  for (auto i = 0; i < n; i++)
#define foitr(it, l) for (auto it = l.begin(); it != l.end(); it++)

typedef long double ld;
typedef unsigned long int ull;
typedef long long int ll;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end() //sortall(v1)
#define clr(a) memset(a, a.size(), 0)

#define PI 3.1415926535897932384626433832795
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef multiset<int> msi;

ll damage(ll time, vll v1){
    ll damageDealt=0; 

    fo(i, v1.size()){

        if (i==v1.size()-1){
            damageDealt+=time;
        }else{
            damageDealt += min(v1[i+1]-v1[i], time);
        }
    }

    return damageDealt;
}


void solve() {

    ll n, h; cin>>n>>h; 

    vll v1(n); 
    fo(i, n) cin>>v1[i];

    //apply binary search for k 

    ll lo=0, hi=1000000000000000000;

    ll ans=hi;

    while(lo <= hi){
        ll mid = hi -(hi-lo)/2; 

        if (damage(mid, v1) >= h){
            ans = mid; 
            hi=mid-1; 
        }else{
            lo=mid+1; 
        }
    }

    cout << ans << endl;
    
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   
    int tc; cin >> tc;
    fo(i, tc) {
        solve();
    }

}




