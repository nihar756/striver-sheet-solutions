// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long count(vector<int>&nums,int cap){
        long long ans=1;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=cap){
                sum+=nums[i];
            }
            else{
                ans++;
                sum=nums[i];
            }
        }
        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        long long lo=*max_element(nums.begin(),nums.end());
        long long hi=accumulate(nums.begin(),nums.end(),0LL);
        if(nums.size()<k)return -1;
        while(lo<=hi){
            long long mid=(lo+hi)/2;

            if(count(nums,mid)>k){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return lo;
    }
};