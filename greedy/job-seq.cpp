// You are given two arrays: deadline[], and profit[], which represent a set of jobs, 
//where each job is associated with a deadline, and a profit. Each job takes 1 unit of 
//time to complete, and only one job can be scheduled at a time. You will earn the profit 
//associated with a job only if it is completed by its deadline.

// Your task is to find:

// The maximum number of jobs that can be completed within their deadlines.
// The total maximum profit earned by completing those jobs.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int maxDL=*max_element(deadline.begin(),deadline.end());
        vector<int>assign(maxDL+1,-1);
        int n=profit.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({profit[i],deadline[i]});
        }
        
        sort(v.rbegin(),v.rend());
        int cnt=0,maxProfit=0;
        for(int i=0;i<n;i++){
            int j=v[i].second;
            while(j>0 && assign[j]!=-1){
                j--;
            }
            if(j<=0)continue;
            else{
                maxProfit+=v[i].first;
                cnt++;
                assign[j]=v[i].second;
            }
        }
        return {cnt,maxProfit};
    }
};

