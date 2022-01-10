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

string worstCase(string s, string ans, int index, int fours, int sevens){
    if (index == s.length()){
        if (ans >= s) return ans; 
        else{
            string max=""; 
            fo(i, s.length()) max += "7"; 
            return max; 
        }
    } 

    if (fours==0){
        return worstCase(s, ans+"7", index+1, fours, sevens-1);
    }
    if (sevens==0){
        return worstCase(s, ans+"4", index+1, fours-1, sevens);
    }

    return min (worstCase(s, ans+"4", index+1, fours-1, sevens), worstCase(s, ans+"7", index+1, fours, sevens-1));

    
    
}

void solve() {
    string s; cin>>s; 
    int n = s.length(); 


    if (n%2 == 1){
        string ans=""; 

        fo(i, (n+1)/2) ans += "4"; 
        fo(i, (n+1)/2) ans += "7";

        cout << ans; 
        return; 

    }else{
        string max ="", min=""; 
        fo(i, (n)/2){
            max += "7"; 
            min += '4';
        } 
        fo(i, (n)/2){
            max += "4";
            min += "7";
        } 

        if (s > max){
            string ans=""; 

            fo(i, (n+2)/2) ans += "4"; 
            fo(i, (n+2)/2) ans += "7";

            cout << ans; 
            return;

        //ans will be less then 77774444
        }else{
            string ans = worstCase(s, ans, 0, n/2, n/2);
            cout << ans; return;
            
        }
    }


    
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    solve();


}




