#include<iostream>
using namespace std;

int main(){
    int size; cin>> size;
    int arr[size];

    for (int i=0; i<size; i++){
        cin >> arr[i];
    }

    for(int k=0; k<size; k++){
        for(int j=0; j<size-1; j++){
            if (arr[j] > arr[j+1]){
                int swap = arr[j]; arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    } 

    
}