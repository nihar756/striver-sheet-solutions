// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than 
// ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

#include<bits/stdc++.h>
using namespace std;

//////using map//////
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        int target=nums.size()/2;
        for(auto it:mp){
            if(it.second>target)return it.first;
        }
        return -1;
    }
};

//////optimized solution/////
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ele;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (cnt == 0){
                cnt = 1;
                ele=nums[i];
            }
            else if(nums[i]==ele)cnt++;
            else cnt--;
        }
        cnt=0;
        for(int it:nums){
        if(it==ele)cnt++;}
        return (cnt>n/2)?ele:-1;
    }
};