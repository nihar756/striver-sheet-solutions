// You are given an array 'arr' of size 'n' which denotes the position of stalls.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.

#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr,int dist,int cows){
    int cnt=1;
    int last=arr[0];

    for(int i=1;i<arr.size();i++){
        if(arr[i]-last >= dist){
            last=arr[i];
            cnt++;
        }

        if(cnt>=cows)return true;
    }
    return false;
}

int solve(vector<int>&stalls,int k){
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int lo=1,hi=stalls[n-1]-stalls[0];

    while(lo<=hi){
        int mid=(lo+hi)/2;

        if(possible(stalls,mid,k)){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return hi;
}