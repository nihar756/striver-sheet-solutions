// Given an integer array nums, find the subarray with the largest sum, and return its sum.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int sum=0;
        for(auto it:nums){
            sum=max(it,sum+it);
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};

////usign dp////
int maxSubArray(vector<int>& nums) {
    //    int maxSum=nums[0];
    //    int curr=nums[0];
    //    for(int i=1;i<nums.size();i++){
    //     curr=max(nums[i],curr+nums[i]);
    //     maxSum=max(maxSum,curr);
    //    } 
      // return maxSum;
      vector<int> dp(nums);
        for(int i = 1; i <nums.size(); i++) 
            dp[i] = max(nums[i], nums[i] + dp[i-1]);        
        return *max_element(begin(dp), end(dp));
    }
