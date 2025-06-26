// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

// The test cases are generated so that there will be an answer

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sum(vector<int>&nums,int div){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum += ceil((double)nums[i]/(double)div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long lo=1,hi=*max_element(nums.begin(),nums.end());
        while(lo<=hi){
            long long mid=(lo+hi)/2;

            if(sum(nums,mid)<=threshold){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
};