// Given an integer array nums, move all 0's to the end of it while maintaining the 
// relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos0=0;
        //int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                pos0=i;
                break;
            }
        }
        int a,j=pos0;
        for(int i=pos0;i<n;i++){
            a=nums[i];
            if(a!=0){
                nums[j]=a;
                j++;
            }
        }
        while(j<n){
            nums[j]=0;
            j++;
        }
    }
};