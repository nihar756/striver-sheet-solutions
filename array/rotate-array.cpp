//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
///my solution////
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       vector<int>temp;
       int n=nums.size();
       k=k%n;
       int i=0;
       for(;i<n-k;i++){
        temp.push_back(nums[i]);
       }
       int j=0;
       while(i<n && j<n){
        nums[j++]=nums[i++];
       }
       for(auto it:temp){
        nums[j++]=it;
       }
    }
};
