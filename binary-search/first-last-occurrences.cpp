// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int n=nums.size();
        if(n==0)return ans;
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>target)hi=mid-1;
            else if(nums[mid]<target)lo=mid+1;
            else{
                ans[0]=mid;
                hi=mid-1;
            }
        }
        lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>target)hi=mid-1;
            else if(nums[mid]<target)lo=mid+1;
            else{
                ans[1]=mid;
                lo=mid+1;
            }
        }
        return ans;
    }
};