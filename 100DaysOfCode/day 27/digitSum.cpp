#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; cin >> t;
    while (t--){
        int n; cin>>n; 

        //nums of form 9+10k 
        int first=-1, last=-1;
        int i=1, j=n;

        
        while (i<=n){
            if (i%10 == 9){
                first = i; 
                break;
            }
            i++;
        } 

        while (j>0){
            
            if (j%10 == 9){
            
                last = j;
                break;
            }
            j--;
        }
        //cout << last <<  " " << first << endl;
        if (last==-1 || first==-1){
            cout << 0 << endl;
        }else{
            cout << (last-first)/10 +1 << endl;
        }


    }
}