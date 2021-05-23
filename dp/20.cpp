#include<bits/stdc++.h>
using namespace std;
int game(int arr[],int beg,int end){
	if(end<=beg)
		return 0;
	if(end-beg==1)
		return max(arr[beg],arr[end]);
	int p1 = game(arr,beg+1,end);
	int p2 = game(arr,beg,end-1);

	if((end-beg+1)%2==1){
		if(p1>p2)//3 possible cases so far arr[beg]+p1>arr[end]+p2 -- arr[beg]-p1<	arr[end]-p2
			return p2;
		else
			return p1;
	}
	return max(arr[beg]+p1,arr[end]+p2);


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
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int dp[n+3][n+3];
	memset(dp,0,sizeof(dp));
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			int p2 = dp[i][j-1];
			int p1 = dp[i+1][j];
			if(j<=i)
				i=i;
			
			else if((j-i)%2){//even condition
				dp[i][j] = max(arr[i-1]+p1,arr[j-1]+p2);
			}
			else{
				if(p1<p2)
					dp[i][j]  = p1;
				else
					dp[i][j]  = p2;
			}//cout<<dp[i][j]<<"\t\t";
		}//cout<<endl;
	}
	cout<<dp[1][n];
	cout<<game(arr,0,n-1);
}