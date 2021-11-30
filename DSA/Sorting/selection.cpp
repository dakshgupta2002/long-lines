#include<iostream>
#include<vector>
using namespace std;

int main(){
    //input variable size of array 
    int n; cin >> n;
    vector<int> v1(n); //initialized the n size array with 0

    for (int i = 0; i<n; i++){
        cin >> v1[i];       //input n integers
    }
   
    for (int j = 0; j<n; j++){  //loop for selecting minimum integer in unsorted array


        int min = 100000000; //10**8 since every element is smaller than 10e8
        int min_index; //will store the index of the least integer

        //looping to find one at a time
        for (int k = j; k<n; k++){
            if (v1[k] < min){
                min = v1[k];
                min_index = k;
            }
        }

        int swap = v1[min_index];       //once min is found, place it the j-th index
        v1[min_index] = v1[j]; v1[j] = min;


    }

    for (int o = 0; o<n; o++){  //print the vector elements space seperated
        cout << v1[o] << " ";
    }
    cout << endl;
}