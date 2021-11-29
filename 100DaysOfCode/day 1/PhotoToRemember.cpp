//JAI MATA DI
//JAI SHREE RAM

#include <bits/stdc++.h>
using namespace std;




#define fo(i,n) for (i = 0; i < n; i++)
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
typedef pair<int, int> PII;
typedef vector<long long> vi;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;




void solve() {
    int n; cin>>n; 

    vi width, height; 
    ll widTot=0, heiMax=0, heiMaxInd=0, secHeiMax=0;

    for (int i=0; i<n; i++){
        ll w,h; cin>>w>>h; 
        width.pb(w); height.pb(h);
        
        widTot+=w;

        if (h > heiMax){ 
            heiMax=h;
            heiMaxInd=i;
        }
    }
    for (int i=0; i<n; i++){
        if (height[i] > secHeiMax && heiMaxInd!=i){
            secHeiMax = height[i];
        }
    }
    
    for(int i=0; i<n; i++){
        ll heightForThis = (height[i] == heiMax)? secHeiMax : heiMax;

        ll pix = (widTot-width[i])*(heightForThis); 
        cout << pix << " ";
    }
    
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

}




