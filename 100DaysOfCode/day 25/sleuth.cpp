#include<bits/stdc++.h>
using namespace std;


int main(){
    char c; 
    while (true){
        char temp; cin >> temp; 
        if (temp == '?') break;

        c = temp; 
    }


    if (c=='a' || c=='A' ||c=='e' ||c=='E' ||c=='i' ||c=='I' ||c=='o' ||c=='O' ||c=='u' ||c=='U' ||c=='y' ||c=='Y'){
        cout << "YES";
    }else{
        cout << "NO";
    }
}