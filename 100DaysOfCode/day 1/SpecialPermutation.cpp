// //JAI MATA DI
// //JAI SHREE RAM

#include <bits/stdc++.h>
using namespace std;

#define push_back push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef multiset<int> msi;




bool solve() {
    int n, a, b; cin>>n>>a>>b;

    vi ans; 
    int left=0, right=0; 

    //set left array
    int i; 
    for (i=n; i>0; i--){        
        if (i==b || i==a) continue;         
        if (i<a)return false;

        //found a number than can fit in first half
        ans.push_back(i); 
        left++;
        if (left == n/2 - 1) break; 
    }
    ans.push_back(a); 

    for (int j=i-1; j>0; j--){
        if (j==a || j==b)continue;
        
        if (j>b)return false; 

        ans.push_back(j);
        right++;
        if (right==n/2 -1) break; 
    }
    ans.push_back(b);

    //just to be double sure i check iteration over all numbers is done
    if (right!=n/2-1 || left != n/2 -1)return false;
    
    //print the solution
    for (int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return true; 

    
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    for (int i = 0; i < tc; i++) {
        
        if (!solve()){
            cout << -1 << endl; 
        }
    }
}




