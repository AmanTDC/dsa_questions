#include<bits/stdc++.h>
using namespace std;
bool subsetsum(int *arr,int n,int k){
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	// for(int i =0;i<n;i++)
	// 	cout<<arr[i] <<" ";
	// cout<<endl;
	// 
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(j==0)
				dp[i][j] = true;
			else if(i==0)
				i=i;
			else if( j - arr[i-1] >= 0){
				dp[i][j] = dp[i-1][j]||dp[i-1][j - arr[i-1]];
			}
			else
				dp[i][j] = dp[i-1][j];
			//cout<<dp[i][j]<<" ";
		}//cout<<endl;
	}
	return dp[n][k];
}
int main(){
	int n;
	#ifndef ONLINE_JUDGE	
	    // for getting input from input.txt
	    freopen("inputf.in", "r", stdin);
	    // for writing output to output.txt
	    freopen("outputf.in", "w", stdout);
	#endif
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int sum =0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	if(!(sum&1))
		cout<<subsetsum(arr,n,sum/2);
	else
		cout<<false;
}