// At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from 
// you and order one at a time (in the order specified by bills). Each customer will only buy 
// one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change 
// to each customer so that the net transaction is that the customer pays $5.

// Note that you do not have any change in hand at first.

// Given an integer array bills where bills[i] is the bill the ith customer pays, return true 
// if you can provide every customer with the correct change, or false otherwise.

#include<bits/stdc++.h>
using namespace std;
////brute force/////
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //int arr={5,10,20};
        unordered_map<int,int>mp;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                mp[5]++;
            }
            else if(bills[i]==10){
                if(mp[5]==0)return false;
                mp[5]--;
                mp[10]++;
            }
            else{
                if(mp[10]==0 && mp[5]<=2)return false;
                if(mp[10]>=1 && mp[5]>=1){
                    mp[10]--;
                    mp[5]--;
                    mp[20]++;
                }
                else if(mp[5]>=3){
                    mp[5]-=3;
                    mp[20]++;
                }
                else return false;
            }
        }
        return true;
    }
};

/////optimized///
bool lemonadeChange(vector<int>& bills) {
       if(bills[0]==20 || bills[0]==10) return false;
        int ct5=0;
        int ct10=0;
        for(int i=0;i<bills.size();i++){
            int change=0;
            if(bills[i]==5){
                ct5++;
                continue;
            }
            else if(bills[i]==10){
                ct10++;
               
                if(ct5<=0) return false;
                else{
                    ct5--;
                }
            }
            else{
                if(ct10>=1 && ct5>=1){
                    ct10--;
                    ct5--;
                }
                else if(ct5>=3){
                    ct5-=3;
                }
                else{
                    return false;
                }
            }
        }
    return true;
}