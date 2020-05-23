#include "main.hpp"

int main(){
    vector<int> a{};
    vector<int> b{};
    int l=0;
    getElements(a);
    int r = a.size();
    mergesort(a, b, l, r-1);
    print(b);
    return 0;
}