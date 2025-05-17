// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

#include<bits/stdc++.h>
using namespace std;

////brute force
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        int i=0,j=0;
        vector<int>ans;
        while(i<pos.size() && j<neg.size()){
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }
        return ans;
    }
};

// space optimized/////
vector<int> rearrangeArray(vector<int>& nums) {
        int posIdx=0;
        int negIdx=0;
        int n=nums.size();
        vector<int>ans;
        while(posIdx<n && negIdx<n){
           while(posIdx<n && nums[posIdx]<=0)posIdx++;
           while(negIdx<n && nums[negIdx]>=0)negIdx++;
           ans.push_back(nums[posIdx++]);
           ans.push_back(nums[negIdx++]);
        }
        return ans;
    }


