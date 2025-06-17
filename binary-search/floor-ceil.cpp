#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int lo=0,hi=a.size()-1;
	int floor=-1,ceil=-1;
	//floor
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(a[mid]<=x){
			floor=a[mid];
			lo=mid+1;
		}
        else
		hi=mid-1;
	}
	
	//ceil
    lo=0,hi=a.size()-1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(a[mid]>=x){
			ceil=a[mid];
			hi=mid-1;
		}
		else
		lo=mid+1;
	}
	return {floor,ceil};
}