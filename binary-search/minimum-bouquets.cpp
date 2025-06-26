// You are given an integer array bloomDay, an integer m and an integer k.

// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int>&arr,int day,int m,int k){
        long long cnt=0;
        long long B=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<day){
                cnt++;
            }
            else{
                B += cnt/k;
                cnt=0;
            }
        }
        B+=cnt/k;

        return B>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long lo=bloomDay[0];
        long long hi=bloomDay[0];
        int n=bloomDay.size();

        long long val=(long long)m*k;
        if(val>n)return -1;

        for(auto day:bloomDay){
            lo=min(lo,(long long)day);
            hi=max(hi,(long long)day);
        }
        
        while(lo<=hi){
            long long mid=(lo+hi)/2;

            if(possible(bloomDay,mid,m,k)){
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return hi;
    }
};