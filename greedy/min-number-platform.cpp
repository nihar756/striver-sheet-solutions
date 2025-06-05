// We are given two arrays that represent the arrival and departure times of trains that stop at 
// the platform. We need to find the minimum number of platforms needed at the railway station so 
// that no train has to wait.

#include<bits/stdc++.h>
using namespace std;

///brute force///
int countPlatforms(int n,int arr[],int dep[])
 {
    int ans=1; //final value
    for(int i=0;i<=n-1;i++)
    {
        int count=1; // count of overlapping interval of only this   iteration
        for(int j=i+1;j<=n-1;j++)
        {
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
           (arr[j]>=arr[i] && arr[j]<=dep[i]))
           {
               count++;
           }
        }
        ans=max(ans,count); //updating the value
    }
    return ans;
 }

 ///optimal///
 int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int n=arr.size();
        int i=1,j=0;
        int cnt=1,ans=1;
        while(i<n&& j<n){
            if(arr[i]<=dep[j]){
                cnt++;
                i++;
            }
            else {
                cnt--;
                j++;
            }
            ans=max(ans,cnt);
        }
        return ans;
} 