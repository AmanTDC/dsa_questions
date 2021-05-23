#include<bits/stdc++.h>
using namespace std;
int maxProductCut(int n){
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	int max_ = INT_MIN;
	for(int i=1;i<n;i++){
		max_ = max(max_ , max(i,maxProductCut(i))*max(n-i,maxProductCut(n-i)));
	}
	return max_;

}
int main(){
	int n = 10;
	//cout<<maxProductCut(n);	
	int dp[n+1];

	memset(dp,0,sizeof(dp));
	dp[2] = 1;
	for(int i=3;i<=n;i++){
		int max_ = INT_MIN;
		
		for(int j=1;j<=i/2;j++)
			max_ = max(max_ , max(j,dp[j])*max(i-j,dp[i-j]));
		
		dp[i] = max_;
	}
	cout<<dp[n];
}