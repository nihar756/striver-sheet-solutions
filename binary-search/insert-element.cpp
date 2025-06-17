// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity

#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>&nums,int target){
    int n=nums.size();
    int lo=0,hi=n-1;
    int ans=n;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(nums[mid]>=target){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}