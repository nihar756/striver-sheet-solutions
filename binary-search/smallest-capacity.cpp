// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countDays(vector<int>&nums,long long cap){
        long long days=1;
        long long load=0;
        for(int i=0;i<nums.size();i++){
            if(load+nums[i]>cap){
                days++;
                load=nums[i];
            }
            else{
                load+=nums[i];
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long lo=*max_element(weights.begin(),weights.end());
        long long hi=accumulate(weights.begin(),weights.end(),0LL);

        while(lo<=hi){
            long long mid=(lo+hi)/2;

            if(countDays(weights,mid)<=days){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
};