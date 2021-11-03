#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){

    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);        


    int t; cin>>t;
    while(t--){
        string keyboard; cin>>keyboard; 
        string s; cin>>s; 

        int i=0;
        while(true){
            if (keyboard[i] == s[0]){
                break;
            }
            i++;
        }
        int time=0; int last_ind=i;

        for(int i=1; i<s.length(); i++){
            int j=0; 
            while(true){
                if (keyboard[j] == s[i]){
                    break;
                }
                j++;
            }
            time+=abs(last_ind-j);
            last_ind = j;

        }   

        cout << time << endl;
    }

    return 0; 

}



