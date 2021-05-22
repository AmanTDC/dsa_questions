#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>p1,pair<int,int>p2){
	if(p1.second==p2.second)
		return p1.first<p2.first;
	return p1.second<p2.second;
}
int lisVar(vector<pair<int,int>>&arr){
	int dp[arr.size()];
	int n = arr.size();
	for(int i=0;i<arr.size();i++)
		dp[i] = 1;

	for(int i=0;i<n-1;i++){
		for(int j=1;j<n;j++){
			if(arr[i]<arr[j]){
				dp[j] = max(dp[j],1+dp[i]);
			}
		}
	}
	int res = 1;
	for(int i : dp){
		res = max(res,i);
	}
	return res;

}
int main(){
	#ifndef ONLINE_JUDGE	
	    // for getting input from input.txt
	    freopen("inputf.in", "r", stdin);
	    // for writing output to output.txt
	    freopen("outputf.in", "w", stdout);
	#endif
	int n;
	cin>>n;

	vector<pair<int,int>> arr(n,pair<int,int>());
	for(int i=0;i<n;i++)
		cin>>arr[i].first;
	for(int i=0;i<n;i++)
		cin>>arr[i].second;
	sort(arr.begin(),arr.end(),compare);
	
	cout<<lisVar(arr);

}