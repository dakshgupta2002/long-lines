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

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll indexOfHBound(vector<ll> v1, ll h){

    ll hi=v1.size()-1, lo=0;
    ll ans=hi;

    while(lo<=hi){
        ll mid = hi -(hi-lo)/2;

        if(v1[mid]>= h){
            ans=mid;
            hi=mid-1; 
        }else{
            lo=mid+1;
        }
    }

    return ans; 
}

ll indexOfLBound(vector<ll> v1, ll h){

    ll hi=v1.size()-1, lo=0;
    ll ans=lo;

    while(lo<=hi){
        ll mid = hi -(hi-lo)/2;

        if(v1[mid]<= h){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1; 
        }
    }

    return ans; 
}

void solve() {

    ll n, l, r; cin>>n>>l>>r;


    vll v1(n);
    fo(i, n) cin>>v1[i];


    sort(all(v1)); 
    // unordered_map<ll, ll> m1; 
    // fo(i, n) m1[v1[i]]=i; 

    ll ans=0; 
    fo(i, n-1){        
        //search        
        ll upperlimit=max(i+1LL, indexOfLBound(v1, r-v1[i]));
        ll lowerlimit=max(i+1LL, indexOfHBound(v1, l-v1[i]));

        //deb(v1[i]); deb(lowerlimit); deb(upperlimit);



        if(v1[i]+v1[lowerlimit] > r || v1[i]+v1[upperlimit] > r ||
            v1[i]+v1[lowerlimit] < l || v1[i]+v1[upperlimit] < l){
            ans=ans;
        }else ans += max(0LL, upperlimit-lowerlimit+1);
    
        //deb(ans);

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




