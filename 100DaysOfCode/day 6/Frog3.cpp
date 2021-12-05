//JAI MATA DI
//JAI SHREE RAM

#include <bits/stdc++.h>
using namespace std;


#define fo(i, n)  for (auto i = 0; i < n; i++)
#define foitr(it, l) for (auto it = l.begin(); it != l.end(); it++)
typedef long long int ll;

#define pb push_back
typedef vector<long long> vll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   
    ll n; cin>>n; 
    vll h(1); 
    //index 1 to n i have heights stored
    fo(i, n){
        ll h1; cin>>h1; 
        h.pb(h1);
    }
    //start == end
    if (n==1){
        cout << 0 << endl; 

    }else{
        ll last=0, curr=abs(h[n]-h[n-1]);

        for (int i = n-2; i>=1; i--){
            ll temp = curr; 
            curr = min(curr+abs(h[i]-h[i+1]), last+abs(h[i+2]-h[i]));
            last = temp;
        }   

        cout << curr << endl;

    }
}




