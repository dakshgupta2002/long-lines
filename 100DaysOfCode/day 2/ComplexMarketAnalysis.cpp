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

bool prime(int n){
    if (n==1)return false; 
    if (n==2 || n==3) return true; 

    for (int i=2; i*i <=n; i++){
        if (n%i == 0) return false;
    }
    return true;
}


void solve() {
    int n, e; cin>>n>>e; 
    vi v1(n); 
    fo(i, n) cin>>v1[i];

    ll solution=00; 
    //select i 
    for (int i=0; i < n; i++){
        if (prime(v1[i])){
            ll left=0, right=0; 

            for (int j=i+e; j<n; j+=e){
               // deb(j);
                if (v1[j]==1){
                    right++;
                }else break;
            }

            for(int k=i-e; k>=0; k-=e){
                if (v1[k]==1) left++;
                else break; 
            }
            //deb(solution);
            solution +=1LL*(left*(right+1) + right);
        }
        

    }

    cout << solution<< endl;

}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   
    int tc; cin >> tc;
    fo(i, tc) {
        solve();
    }

}




