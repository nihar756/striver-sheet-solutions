// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int resHours(vector<int>& piles,long long int h){
        long long int totalH=0;
        for(int i=0;i<piles.size();i++){
            totalH += ceil((double)piles[i]/(double)h);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int lo=1,hi=*max_element(piles.begin(),piles.end());
        long long int ans=-1;
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            long long int totalH=resHours(piles,mid);
            if(totalH<=h){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};
