// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it .

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        ans[0]={1};
        for(int i=1;i<numRows;i++){
           vector<int>row(i+1);
           vector<int>prev=ans[i-1];
           row[0]=1;
           for(int j=1;j<prev.size();j++){
            row[j]=prev[j]+prev[j-1];
           }
           row[prev.size()]=1;
           ans[i]=row;
        }
        return ans;
    }
};