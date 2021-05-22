#include<bits/stdc++.h>
using namespace std;
/*int eggdrop(int floors,int eggs){
	if(eggs == 1)
		return floors;
	if(floors==0)
		return 0;
	int min_ = INT_MAX;
	for(int i=1;i<=floors;i++){
		min_ = min(min_ , 1 + max(eggdrop(floors-i,eggs),eggdrop(i-1,eggs-1)));
	}
	//cout<<min_<<" "<<floors<<" "<<eggs<<endl;
	return min_;

}*/
int main(){
	#ifndef ONLINE_JUDGE	
	    // for getting input from input.txt
	    freopen("inputf.in", "r", stdin);
	    // for writing output to output.txt
	    freopen("outputf.in", "w", stdout);
	#endif
	int floors;
	int eggs;
	cin>>floors>>eggs;
	//cout<<eggdrop(floors,eggs);
	int dp[floors+1][eggs+1];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<=floors;i++){
		for(int j=1;j<=eggs;j++){
				//	cout<<i;

			if(i==0)

				dp[i][j] = 0;
			else if(j==1)
				dp[i][j] = i;
			else{
				int res = INT_MAX;
				for(int ind = 1;ind<=i;ind++){
					res = min(res,1+max(dp[i-ind][j],dp[ind-1][j-1]));
				}
				dp[i][j] = res;
			}
			//cout<<dp[i][j]<<" ";
		}//cout<<endl;
	}
	cout<< dp[floors][eggs];
}