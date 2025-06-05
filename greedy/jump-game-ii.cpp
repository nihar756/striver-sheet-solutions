// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, 
//if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can 
//reach nums[n - 1].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size()-1)return 0;
        if(dp[idx]!=-1)return dp[idx];

        int ans=1e9+7;
        for(int j=1;j<=nums[idx];j++){
            ans=min(ans,1+solve(idx+j,nums,dp));
            dp[idx]=ans;
        }
        return ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};


// int jump(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n,INT_MAX);
//         //return solve(0,nums,dp);
//         dp[0]=0;
//         for(int i=0;i<n;i++){
//             for(int j=1;j<=nums[i];j++){
//                if(i+j<n){
//                 dp[i+j]=min(dp[i+j],1+dp[i]);
//                }
//             }
//         }
//         return dp[n-1];
// }

int jump(vector<int>& nums) {



        int cur_pos = 0;
        int max_jump_pos = 0;
        int res=0 ;

        int n = nums.size();
        for(int i = 0 ; i< n -1;i++){
            max_jump_pos  = max(i+ nums[i],max_jump_pos);
            if(i == cur_pos){
                cur_pos = max_jump_pos;
                res++;
            }
        }

        return res;
        
        
}