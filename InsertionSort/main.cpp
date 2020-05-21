// Insertion Sort

#include<iostream>
#include<vector>
#include<ctype.h>
#include<chrono>

using namespace std::chrono;
using namespace std;

int main(){
    vector<int> arr = {};
    int ele = 0, swap = 0;
    cout<<"Enter elements (enter -1 when done) ";
    while(1){
        cin>>ele;
        if(ele != -1)
            arr.push_back(ele);
        else
            break;
    }
//  sorting
    auto start = high_resolution_clock::now();
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j > 0; j--){
            if(arr[j] < arr[j-1]){
                swap = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = swap;
            }
            else 
                break;
        }
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    for(int k : arr){
        cout<<k<<" ";
    }
    cout<<"\ntime taken : "<<duration.count();
    return 0;
}

