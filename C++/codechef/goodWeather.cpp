#include<iostream>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int sunny = 0;

        for (int i=0; i<7;i++){
            int yn; cin>>yn;
            sunny+=yn;
        }

        if (sunny>=4){
            cout << "YES";
        }else{
            cout << "NO" ;
        }
        //git ssh test login switch 
        cout << endl;
    }
}