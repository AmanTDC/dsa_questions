#include<bits/stdc++.h>
using namespace std;
string a , b ,c;
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{   string a = A,b=B,c=C;
    int dp[a.length()][b.length()][c.length()];
	memset(dp,0,sizeof(dp));
	dp[0][0][0] = ((a[0]==b[0]==c[0]));
 	for(int i=1;i<a.length();i++)
		dp[i][0][0] = dp[i-1][0][0]||(a[i]==b[0]==c[0]);
	for(int i=1;i<b.length();i++)
		dp[0][i][0] = dp[0][i-1][0]||(a[0]==b[i]==c[0]);
	for(int i=1;i<c.length();i++)
		dp[0][0][i] = dp[0][0][i-1]||(a[0]==b[0]==c[i]);

	for(int i=1;i<a.length();i++){
		for(int j=1;j<b.length();j++){
			for(int k=1;k<c.length();k++){
				if(a[i]==b[j]){
					if(b[j]==c[k])
						dp[i][j][k] = 1+dp[i-1][j-1][k-1];
		
					else
						dp[i][j][k] = max(dp[i-1][j-1][k],dp[i][j][k-1]);
				}
				else if(b[j]==c[k]){
					dp[i][j][k] = max(dp[i][j-1][k-1],dp[i-1][j][k]);
				}
				else if(a[i]==c[k]){
					dp[i][j][k] = max(dp[i-1][j][k-1],dp[i][j-1][k]);
				}
				else
					dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
			}
		}
	}
	return dp[a.length()-1][b.length()-1][c.length()-1];
    // your code here
}
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