#include<bits/stdc++.h>
using namespace std;
int solutions(vector<int>&arr,int ind,int rhs){
	if(rhs==0)
		return 1;
	if(rhs<0)
		return 0;
	int sum = 0;
	for(int i=ind;i<arr.size();i++)
		sum += solutions(arr,i,rhs-arr[i]);
	
	return sum;
}
int main(){
	int n = 5;
	vector<int> arr = {
		1,2
	};

	//for(int i=0;i<=n;i++)
	//cout<<solutions(arr,0,i);

/*	int dp[arr.size()][n+1];
	for(int i=0;i<=arr.size();i++){
		for(int j=0;j<=n;j++){
			if(j==0)
				dp[i][j]=1;
			
			else{
				dp[i][j] = 0;
				for(int k=0;k<=i;k++)
					if(j-arr[k]>=0)
						dp[i][j] += dp[k][j-arr[k]];
			}
		}
	}
	cout<<dp[arr.size()-1][n];
*/	

	//More Optimized
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;

	for(int i=0;i<arr.size();i++){
		for(int j = arr[i];j<=n;j++){
			dp[j] += dp[j-arr[i]];
		}
	}
	cout<<dp[n];

}