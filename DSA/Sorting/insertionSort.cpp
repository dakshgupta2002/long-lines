#include<iostream>
#include<vector>
using namespace std;

int main(){
    int size; cin>>size;
    vector<int> v1(size);
    for (int y=0; y<size; y++){
        cin >> v1[y];
    }

    //insertion sort
    for (int i=1; i<size; i++){
        for (int j=i-1; j>=0; j--){
            if (v1[j]>v1[j+1]){
                int temp = v1[j+1]; v1[j+1] = v1[j]; v1[j]=temp;
            }else{
                break;
            }
        }
    }

    for (int u=0; u<size; u++){
        cout << v1[u] << " ";
    }
}