#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){

    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);        


    int t; cin>>t;
    while(t--){
        int x, n; cin >>x>>n;
        if (n == 0){
            cout << x << endl;
        }else if (n==1){
            if (x%2==0){
                cout << x-1 << endl;
            }else{
                cout << x+1 << endl;
            }
        }
        else{

            if (x%2==0){
                x-=1; 
                x-=4*((n-1)/4);
                if ((n-1)%4==1){
                    x+=n;
                }else if ((n-1)%4==2){
                    x+=2*n-1;
                }else if((n-1)%4 == 3){
                    x = x + (n-1) - 2;
                }
            }else{
                x+=1; 
                x+=4*((n-1)/4);
                if ((n-1)%4==1){
                    x-=n;
                }else if ((n-1)%4==2){
                    x-=2*n-1;
                }else if((n-1)%4 == 3){
                    x = x - (n-1)+2;
                }
            }

            cout << x << endl;
        }

    }

    return 0; 

}



