#include<bits/stdc++.h>
using namespace std;
string a , b ,c;
// method for recursive or backtracking method
int lcs(int i,int j ,int k){
	if(i<0||j<0||k<0)
		return 0;
	if(a[i]==b[j]){
		if(b[j]==c[k])
			return 1+lcs(i-1,j-1,k-1);
	}
	return max(lcs(i-1,j,k),max(lcs(i,j-1,k),lcs(i,j,k-1)));

}
int main(){
	#ifndef ONLINE_JUDGE	
	    // for getting input from input.txt
	    freopen("inputf.in", "r", stdin);
	    // for writing output to output.txt
	    freopen("outputf.in", "w", stdout);
	#endif
	cin>>a;
	cin>>b;
	cin>>c;
	//cout<<lcs(a.length()-1,b.length()-1,c.length()-1);
	//return 0;

	int dp[a.length()+1][b.length()+1][c.length()+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=a.length();i++){
		for(int j=0;j<=b.length();j++){
			for(int k=0;k<=c.length();k++){
				if(i==0||j==0||k==0)
					dp[i][j][k] = 0;
				else{
					dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
					if(a[i-1]==b[j-1]&&b[j-1]==c[k-1]){
						dp[i][j][k] = max(1+dp[i-1][j-1][k-1],dp[i][j][k]);
					}
				}
				
			}
		}
	}
	
	cout<<dp[a.length()][b.length()][c.length()];
}