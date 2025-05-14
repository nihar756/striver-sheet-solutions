// Given an array of integers nums and an integer target, return indices of the two 
// numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not 
// use the same element twice.

// You can return the answer in any order.
#include<bits/stdc++.h>
using namespace std;


/////terative solution////////O(N^2)////////
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
            if((nums[i]+nums[j])==target)
            {
                return {i, j};
            }

            }
        }
        return {};
    }
};
/////hash table solution//////O(N)///////
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int idx1=-1,idx2=-1;
        for(int i=0;i<nums.size();i++){
            if(mp.count(target-nums[i])){
                idx1=mp[target-nums[i]];
                idx2=i;
                break;
            }
            mp[nums[i]]=i;
        }
        return {idx1,idx2};
    }
};

////using sorting and two pointers/////O(NlogN)////////
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; i++){
            v[i].first = nums[i];
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        int l=0, r=n-1;
        vector<int> res(2);
        while(l<r){
            if(v[l].first + v[r].first == target){
                res[0]=v[l].second;
                res[1]=v[r].second;
                break;
            }
            if(v[l].first + v[r].first < target) l++;
            else r--;
        }
        return res;
    }
};
