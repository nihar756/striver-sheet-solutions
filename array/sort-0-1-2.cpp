// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of 
// the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

#include<bits/stdc++.h>
using namespace std;

/////iterative solution/////
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0,cnt1=0,cnt2=0;
        for(int it:nums){
            if(it==0)cnt0++;
            else if(it==1)cnt1++;
            else cnt2++;
        }
        int j=0;
        while(j<nums.size()&&cnt0){
            nums[j++]=0;
            cnt0--;
        }
        while(j<nums.size()&&cnt1){
            nums[j++]=1;
            cnt1--;
        }
        while(j<nums.size()&&cnt2){
            nums[j++]=2;
            cnt2--;
        }
    }
};

/////optimized appraoch/////
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int lo=0,mid=0,hi=n-1;
        while(mid<=hi){
            if(nums[mid]==0){
                swap(nums[lo],nums[mid]);
                lo++;
                mid++;
            }
            else if(nums[mid]==1)mid++;
            else{
                swap(nums[mid],nums[hi]);
                hi--;
            }
        }
    }
};