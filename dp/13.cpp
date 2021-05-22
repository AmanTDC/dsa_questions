#include<bits/stdc++.h>
using namespace std;
//recursive
int lps(string &s,int beg,int end){
	if(beg>end)
		return 0;
	if(s[beg]==s[end])
		return 1 + lps(s,beg+1,end-1);
	return max(lps(s,beg+1,end),lps(s,beg,end-1));
}
int main(){
	#ifndef ONLINE_JUDGE	
	    // for getting input from input.txt
	    freopen("inputf.in", "r", stdin);
	    // for writing output to output.txt
	    freopen("outputf.in", "w", stdout);
	#endif

	string s;
	cin>>s;
	int n = s.length();
	int dp[n+2][n+2];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			if(s[i-1]==s[j-1])
				dp[i][j] = 1+dp[i-1][j+1];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j+1]);

		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}*/
	cout<<dp[n][1];

}