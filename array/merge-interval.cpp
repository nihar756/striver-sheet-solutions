// Given an array of intervals where intervals[i] = [starti, endi], merge all 
// overlapping intervals, and return an array of the non-overlapping intervals 
// that cover all the intervals in the input

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;

        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=0;i<n;i++){
            if(intervals[i][0]<=ans.back()[1]){
                ans.back()[1]=max(intervals[i][1],ans.back()[1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};