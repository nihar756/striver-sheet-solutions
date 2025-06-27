// Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:

// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1

#include<bits/stdc++.h>
using namespace std;

int count(vector<int>&nums,int cap){
    int n=nums.size();
    int cnt=1;
    int pages=0;
    for(int i=0;i<n;i++){
        if(nums[i]+pages<=cap){
            pages+=nums[i];
        }
        else{
            cnt++;
            pages=nums[i];
        }
    }
    return cnt;
}

int solve(vector<int>&pages,int m){
    int n=pages.size();
    if(m>n)return -1;

    int lo=*max_element(pages.begin(),pages.end());
    int hi=accumulate(pages.begin(),pages.end(),0);

    while(lo<=hi){
        int mid=(lo+hi)/2;

        if(count(pages,mid)>m){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return lo;
}