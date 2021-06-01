#include<bits/stdc++.h>
using namespace std;

int sum(int arr[],int i,int n){
	int sum = 0;
	for(;i<=n;i++)
		sum+=arr[i];
	return sum;
}
int painterPartition(int arr[],int n,int k){
	if(n==0)
		return arr[0];
	if(k==1)
		return sum(arr,0,n);
	int min_ = INT_MAX;
	for(int i=0;i<n;i++){
		min_ = min(min_,max(painterPartition(arr,i,k-1),sum(arr,i+1,n)));
	}
	return min_;
	
}
int main(){
	int arr[] = {4,2,22,8,2,11,19,13};
	int len = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	
	//cout<<painterPartition(arr,len-1,k);
	//Optimized

	int dp[len+1][k+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=len;i++)
		for(int j=1;j<=k;j++){
			if(i==1)
				dp[i][j] = arr[i-1];
			else if(j==1)
				dp[i][j] = sum(arr,0,i-1);
			else{
				int min_ = INT_MAX;
				for(int l=1;l<=i;l++){
					min_ = min(min_,max(dp[l][j-1],sum(arr,l,i-1)));
				}
				dp[i][j] = min_;
			}
		}
		cout<<dp[len][k];
		

}
/*
//sumbimtted code


int len = n;
         long dp[][] = new long[len+1][k+1];
         int sum[] = new int[n];
         sum[0] = arr[0];
         for(int i=1;i<n;i++)
            sum[i]=sum[i-1]+arr[i];
	    for(int i=1;i<=len;i++)
		for(int j=1;j<=k;j++){
			if(i==1)
				dp[i][j] = arr[i-1];
			else if(j==1)
				dp[i][j] = sum[i-1];
			else{
				 long min_ = Integer.MAX_VALUE;
				for(int l=1;l<=i;l++){
					min_ = Math.min(min_,Math.max(dp[l][j-1],sum[i-1]-sum[l-1]));
				}
				dp[i][j] = min_;
			}
		}
		return dp[len][k];
*/