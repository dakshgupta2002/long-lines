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
typedef vector<vll> vvll;
typedef map<int,int> mii;



ll wood(ll time, vvll tree, ll l, ll w) {
    ll woodCollected=0; 
    fo(i, tree.size()){
        // tree[i][0] + (tree[i][1])*time >= l; 
        //this is int overflow
        
        if (time >= (l-tree[i][0]+tree[i][1]-1)/tree[i][1]){
            woodCollected+=tree[i][0]; 
            if(woodCollected >= w){
                return true; 
            }
            woodCollected+=tree[i][1]*time; 
            if(woodCollected >= w){
                return true; 
            }
        }
        if(woodCollected >= w){
            return true; 
        }
    }
    return false;    
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   
    ll n, w, l; cin>>n>>w>>l; 
    vvll tree;

    fo(i, n){
        ll h, r; cin>>h>>r; 
        tree.pb({h, r});
    }

    ll hi=1000000000000000001, lo=0; 
    ll ans=hi; 
    while(lo<=hi){
        ll mid= hi - (hi-lo)/2; 

        if (wood(mid, tree, l, w)){
            ans = mid; 
            hi = mid-1;
        }else{
            lo= mid+1;
        }
    }

    cout << ans << "\n";

}




