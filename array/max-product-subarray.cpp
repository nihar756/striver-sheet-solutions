// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())return 0;
        int max_prod=nums[0],min_prod=nums[0],res=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<0)swap(max_prod,min_prod);
            max_prod=max(nums[i],nums[i]*max_prod);
            min_prod=min(nums[i],nums[i]*min_prod);

            res=max(res,max_prod);
        }
        return res;
    }
};