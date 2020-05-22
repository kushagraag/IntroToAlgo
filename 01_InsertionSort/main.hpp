#include<iostream>
#include<vector>
#include<ctype.h>
#include<chrono>

using namespace std::chrono;
using std::vector;
using namespace std;

void start(vector<int> &arr);
auto sorting(vector<int> &arr);
void print(vector<int> &arr, std::chrono::microseconds duration);

    // get values
void start(vector<int> &arr){
    int ele =0;
    cout<<"Enter elements (enter -1 when done) ";
    while(1){
        cin>>ele;
        if(ele != -1)
            arr.push_back(ele);
        else
            break;
    }
}
    //  sorting
auto sorting(vector<int> &arr){
    int swap = 0;
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
    return duration;
}
    // print
void print(vector<int> &arr, std::chrono::microseconds duration){
    cout<<"After Sorting : ";
    for(int k : arr){
        cout<<k<<" ";
    }
    cout<<"\ntime taken : "<<duration.count();
}