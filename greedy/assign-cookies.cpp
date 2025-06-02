// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j 
// has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize 
// the number of your content children and output the maximum number.

#include<bits/stdc++.h>
using namespace std;

///brute force////
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n=g.size(),m=s.size();

        int i=0,j=0;
        while(i<n && j<m){
            while(j<m && s[j]<g[i]){
                j++;
            }
            if(j==m)return cnt;
            else {
                i++;j++;cnt++;
            }
        }
        return cnt;
    }
};