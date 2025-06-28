// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

#include<bits/stdc++.h>
using namespace std;

////brute force//
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        bool even= (n+m)%2==0;
        vector<int>merge(n+m);
        int i=0,j=0,k=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                merge[k++]=nums1[i++];
            }
            else{
                merge[k++]=nums2[j++];
            }
        }

        while(i<n){
            merge[k++]=nums1[i++];
        }
        while(j<m){
            merge[k++]=nums2[j++];
        }
        int mid=(n+m)/2;
        if(even)return (double)(merge[mid]+merge[mid-1])/2.0;
        return merge[mid];
    }
};

//better approach//
double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}


///optimal approach
double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    //if n1 is bigger swap the arrays:
    if (n1 > n2) return median(b, a);

    int n = n1 + n2; //total length
    int left = (n1 + n2 + 1) / 2; //length of left half
    //apply binary search:
    int low = 0, high = n1;
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement
}
