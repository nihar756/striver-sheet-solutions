// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum 
// number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] 
// are non-overlapping.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());

        int cnt=0;
        int prev=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prev){
                cnt++;
                prev=min(prev,intervals[i][1]);
            }
            else{
                prev=intervals[i][1];
            }
        }
        return cnt;
    }
};