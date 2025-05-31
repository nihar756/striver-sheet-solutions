// Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

#include<bits/stdc++.h>
using namespace std;


/////brute force/////
bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

///optimal/////
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(auto it:nums)st.insert(it);

        int longest=0;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                while(st.find(it+1)!=st.end()){
                    cnt++;
                    it=it+1;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};