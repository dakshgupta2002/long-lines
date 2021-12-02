// JAI MATA DI
// JAI SHREE RAM

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define sum(a) accumulate(a.begin(), a.end(), 0);

#define fo(i, n) for (auto i = 0; i < n; i++)
#define foitr(it, l) for (auto it = l.begin(); it != l.end(); it++)

typedef long double ld;
typedef unsigned long int ull;
typedef long long int ll;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end() // sortall(v1)
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
typedef unordered_map<int, int> mii;
typedef set<int> si;
typedef multiset<int> msi;

void solve()
{
    mii m1;
    int n;
    cin >> n;
    //deb(n);
    vi v1(n);
    fo(i, n)
    {
        cin >> v1[i];
        m1[v1[i]]++;
    }

    sort(v1.begin(), v1.end(), greater<int>());
    //deb(v1[0]);deb(v1[1]);
    for (int i=0; i<n/2; i++){
        cout << v1[i] << " " << v1[n-1] << endl;
    }

    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    fo(i, tc)
    {
        solve();
    }
}
