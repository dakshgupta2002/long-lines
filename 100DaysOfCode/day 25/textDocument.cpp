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

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}


void solve() {
    int n; cin >> n; 
    string s="";
    fo(i, n){
        char c; cin>>c; 
        s+=c;
    } 
    
    int max_length=0; 
    int word_paranthesis=0; 
    
    fo(i, n){
        int length=0; 
        while (i<n && (s[i]!='(' && s[i]!=')' && s[i]!='_' ) ){
            length++; 
            max_length = max(max_length, length);
            //deb(s[i]); deb(max_length);
            i++;
        }
        if (s[i] == '('){
            i++;
            
            while (s[i] != ')'){
                
                
                if (s[i]!='_' && s[i]!=')'){
                    //deb(s[i]);
                    word_paranthesis++; 
                    while (s[i]!='_' && s[i]!=')'){
                        //deb(s[i]);
                        i++;

                    } 
                }

                if (s[i]=='_') i++;

            
            }
        }
        max_length = max(max_length, length);
    }

    cout << max_length << " " << word_paranthesis;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   
    
    solve();


}




