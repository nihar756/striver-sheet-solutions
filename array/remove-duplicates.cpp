// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears 
// only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums 
// initially. The remaining elements of nums are not important as well as the size of nums.
// Return k.
// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.
#include<bits/stdc++.h>
using namespace std;

////my solution//////
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>temp;
        int i=0;
        int n=nums.size();
        while(i<n){
            temp.push_back(nums[i]);
            int j=i;
            while(j<n && nums[i]==nums[j]){
                j++;
            }
            i=j;
        }
        nums=temp;
        return temp.size();
    }
};
////using set///
int removeDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}

////more space optimized/////
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i=0;
        for(int j=1;j<arr.size();j++){
            if(arr[i]!=arr[j]){
                arr[++i]=arr[j];
            }
        }
        return i+1;
    }
};