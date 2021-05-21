#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE	
    // for getting input from input.txt
    freopen("inputf.in", "r", stdin);
    // for writing output to output.txt
    freopen("outputf.in", "w", stdout);
#endif
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	int target ;
	cin>>target;
	int dp[n+1][target+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=n;i++)
		dp[i][0] = 1;
	for(int item= 1;item<=n;item++){
		for(int cur_weight = 0;cur_weight<=target;cur_weight++){
			if(cur_weight-arr[item]>=0 ){
				dp[item][cur_weight] = dp[item-1][cur_weight] || dp[item-1][cur_weight-arr[item]];
			}
			else
				dp[item][cur_weight] = dp[item-1][cur_weight];
			cout<<dp[item][cur_weight]<<" ";
		}
		cout<<endl;
	}
	if(dp[n][target]==1)
			cout<<"Exist";

}