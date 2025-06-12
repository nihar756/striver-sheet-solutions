// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/// better///
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                unordered_set<long long>hash;
                for(int k=j+1;k<n;k++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    long long rem=target-sum;
                    if(hash.find(rem)!=hash.end()){
                        st.insert({nums[i],nums[j],(int)rem,nums[k]});
                    }
                    hash.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        //set<vector<int>>st;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int lo=j+1,hi=n-1;
                while(lo<hi){
                    long long temp=nums[i];
                    temp+=nums[j];
                    temp+=nums[lo];
                    temp+=nums[hi];

                    if(temp==target){
                        ans.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                        lo++,hi--;
                        while(lo<hi && nums[lo]==nums[lo-1])lo++;
                        while(lo<hi && nums[hi]==nums[hi+1])hi--;
                    }
                    else if(temp<target)lo++;
                    else hi--;
                }
            }
        }
        //vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};