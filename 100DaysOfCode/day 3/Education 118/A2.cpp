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
typedef map<int, int> mii;
typedef set<int> si;
typedef multiset<int> msi;

void solve()
{
    ld x1, x2, p1, p2;
    cin >> x1 >> p1;
    cin >> x2 >> p2;


    
     if (p1 > p2)
    {
        x2 = x2 / (pow(10, (p1 - p2)));
        //deb(x2);
    }
    else if (p2 > p1)
    {
        x1 = x1 / pow(10 , (p2 - p1));
        //deb(x1);
    }


    if (x1 > x2)
    {
        cout << ">" << endl;
    }
    else if (x1 < x2)
    {
        cout << "<" << endl;
    }
    else
    {
        cout << "=" << endl;
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
