#include<bits/stdc++.h>
using namespace std;
int recursivesol(int n ,int k){
	if(k==1)
		return 1;
	if(k>n)
		return 0;
	return recursivesol(n-1,k-1) + k*recursivesol(n-1,k);
}
int main(){
	#ifndef ONLINE_JUDGE	
	    // for getting input from input.txt
	    freopen("inputf.in", "r", stdin);
	    // for writing output to output.txt
	    freopen("outputf.in", "w", stdout);
	#endif
	int n;
	int k;
	cin>>n>>k;
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=n;i++){
		dp[i][1] = 1;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j] = dp[i-1][j-1] + j*dp[i-1][j];

		}
	}
	
	cout<<dp[n][k];
}