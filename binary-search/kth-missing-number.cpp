// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array

#include<bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
        int lo=0,hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return k+hi+1;
}