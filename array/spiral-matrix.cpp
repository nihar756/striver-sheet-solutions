// Given an m x n matrix, return all elements of the matrix in spiral order.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int n=matrix.size();
       int m=matrix[0].size();
       vector<int>ans;
       int left=0;
       int right=m-1;
       int top=0;
       int bottom=n-1;

       while(left<=right && top<=bottom){
        for(int i=top;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        if(top>right)break;
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        if(top>bottom)break;
        right--;

        for(int i=right;i>=left;i--){
            ans.push_back(matrix[bottom][i]);
        }

        if(right<left)break;
        bottom--;
        for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]);
        }
        if(top>bottom)break;
        left++;
       }
       return ans;
    }
};