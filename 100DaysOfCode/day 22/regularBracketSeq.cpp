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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef multiset<int> msi;


void solve() {

    string s; cin>>s; 
    if (s.length()%2!=0 || s[0]==')' || s[s.length()-1]=='('){
        cout << "NO" << endl;
        return; 
    }

    int open,close;


    for (int i=0; i<s.length(); i++){
        if (s[i]=='('){
            open=i;
        }
        if (s[i]==')'){
            close = i;
        }
    }

    if (open+2==close){
        if (open+3 < s.length() || open-1 >=0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        cout << "YES" << endl;
    }

    

}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   
    int tc; cin >> tc;
    fo(i, tc) {
        solve();
    }

}




