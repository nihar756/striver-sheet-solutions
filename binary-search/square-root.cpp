#include<bits/stdc++.h>
using namespace std;

int findSquareRoot(int n){
    int lo=1,hi=n;
    while(lo<=hi){
        long long mid=(lo+hi)/2;
        if(mid*mid<=n){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return hi;
}