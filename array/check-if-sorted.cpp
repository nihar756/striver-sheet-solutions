// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions 
// (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that
// B[i] == A[(i+x) % A.length] for every valid index i.
#include<bits/stdc++.h>
using namespace std;

/////my solution///////
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                idx=i+1;
                break;
            }
        }
        for(int i=idx;i<idx+n-1;i++){
            if(nums[i%n]>nums[(i+1)%n])return false;
        }
        return true;
    }
};

/////optimal////
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
            }
        }
        if (nums.back() > nums.front()) {
            count++;
        }
        return count <= 1;
    }
};