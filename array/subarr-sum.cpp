// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int>mp;
        int cnt=0;
        int n=nums.size();
        mp[0]=1;
        for(int i=0;i<n;i++){
           sum+=nums[i];

           if(mp.find(sum-k)!=mp.end())cnt+=mp[sum-k];
           mp[sum]++;
        }
        return cnt;
    }
};