//  You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

#include<bits/stdc++.h>
using namespace std;

int count_occurrences(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int n=nums.size();
        if(n==0)return 0;
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
        return ans[1]-ans[0]+1;

    }