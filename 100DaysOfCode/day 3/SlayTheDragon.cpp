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
    ll n;
    cin >> n;

    ll totalStrength = 0; // sum of all heroes's strength

    vll strength(n);
    fo(i, n)
    {
        cin >> strength[i];
        totalStrength += strength[i];
    }

    sort(all(strength)); // sorted vector of strengths


    ll m; cin >> m;
    fo(j, m)
    { // for each dragon choose who will go to fight
        ll attack, defense;
        cin >> defense >> attack;

        ll whoWillAttack = n - 1;

        //binary search to find just the lower bound of the attacker
        //if nobody has strength greater than defense, then choose maximum index
        ll lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            ll mid = hi - (hi - lo) / 2;

            if (strength[mid] == defense)
            {
                whoWillAttack = mid;
                break;
            }
            else if (strength[mid] < defense)
            {
                lo = mid + 1;
            }
            else
            {
                whoWillAttack = mid;
                hi = mid - 1;
            }
        }

        // now either pick just above or just below
        ll coins1 = 1000000000000000000, coins2 = 1000000000000000000;

        coins1 = max(defense-strength[whoWillAttack], 0LL)+max(attack-totalStrength+strength[whoWillAttack], 0LL);

        // check for whoWillAttack-1
        if (whoWillAttack- 1>= 0)
        {
            // set coins2
            coins2 = max(defense-strength[whoWillAttack-1], 0LL)+max(attack - totalStrength + strength[whoWillAttack-1], 0LL);
        }

        cout << min(coins1, coins2) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}
