#include<iostream>
#include<vector>

using namespace std;
using std::vector;

void print(vector<int> &a);
void getElements(vector<int> &a);
void mergesort(vector<int> &a, vector<int> &b, int l, int r);
void merge(vector<int> &a, vector<int> &b, int l, int m, int r);

void print(vector<int> &b){
    for(int i : b){
        cout<<i<<" ";
    }
}


void getElements(vector<int> &a){
    int ele;
    cout<<"Enter elements (-1 when finished)";
    while(1){
        cin>>ele;
        if(ele != -1)
            a.push_back(ele);
        else
            break;
    }
}

void mergesort(vector<int> &a, vector<int> &b, int l, int r){
    if(l<r){
        int m = l + (r-1)/2;

        mergesort(a, b, l, m);
        mergesort(a, b, m+1, r);

        merge(a, b, l, m, r);
    }
}

void merge(vector<int> &a, vector<int> &b, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L{};
    vector<int> R{};
    
    for(int i=0; i<n1; i++)
        L.push_back(a[l+i]);
    for(int j= 0; j< n2; j++)
        R.push_back(a[m+1+j]);

    // b.clear();

    int i=0, j=0;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            b.push_back(L[i]);
            i++;
        }
        else{
            b.push_back(R[j]);
            j++;
        }
    }

    while(i<n1){
        b.push_back(L[i]);
        i++;
    }
    while(j<n2){
        b.push_back(L[j]);
        j++;
    }
    // for(int i: b){
    //     cout<<i<<" ";
    // }
    cout<<"\n";
}