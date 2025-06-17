#include<bits/stdc++.h>
using namespace std;

int upper_bound(vector<int>&nums,int target){
    int n=nums.size();
    int lo=0,hi=n-1;
    int ans=n;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(nums[mid]>target){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}