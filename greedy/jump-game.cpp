// You are given an integer array nums. You are initially positioned at the array's 
// first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        //if(nums[0]==0 && n>1)return false;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            //if(nums[i]==0)continue;
            if(mp[i]==1){
            for(int j=i+1;j<min(n,i+nums[i]+1);j++){
                mp[j]=1;
            }}
            else return false;
            if(mp[n-1]==1)return true;
        }
        return false;
    }
};

///optimal//

 bool canJump(vector<int>& nums) {
        int n =nums.size();
        int maxJumpIdx =0;
        for(int i=0;i<n;i++){
            if(i>maxJumpIdx) return false;
            maxJumpIdx = max(maxJumpIdx,nums[i]+i);
        }
        return true;
}