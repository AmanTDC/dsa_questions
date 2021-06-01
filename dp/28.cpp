#include<bits/stdc++.h>
using namespace std;
bool wildCard(string text, string pattern, int i,int j){
	if(i==text.length()&&j==pattern.length())
		return 1;
	if(j==pattern.length()&&i!=text.length())
		return 0;
	if(i==text.length()&&pattern[j]!='*')
		return 0;
	if(i==text.length()&&pattern[j]=='*')
		return wildCard(text,pattern,i,j+1);
	if(pattern[j]=='?'||pattern[j]==text[i])
		return wildCard(text,pattern,i+1,j+1);
	if(pattern[j]=='*')
		return wildCard(text,pattern,i,j+1)||wildCard(text,pattern,i+1,j);
}
int main(){
	string text = "baaabab";
	string pattern = "a*ab";

	int tl = text.length();
	int pl = pattern.length();
	//cout<<wildCard(text,pattern,0,0);
	bool dp[tl+1][pl+1];
	memset(dp,0,sizeof(dp));
	for(int i=tl;i>=0;i--){
		for(int j=pl;j>=0;j--){
			if(i==tl){
				if(j==pl)
					dp[i][j] = 1;
				else if(pattern[j]!='*')
					dp[i][j] = 0;
				else if(pattern[j]=='*')
					dp[i][j] = dp[i][j+1];
			}
			else if(j==pl&&i<tl)
				dp[i][j] = 0;
			else if(pattern[j]=='?'||pattern[j]==text[i])
				dp[i][j] = dp[i+1][j+1];
			else if (pattern[j]=='*')
				dp[i][j] = dp[i+1][j]||dp[i][j+1];
			//cout<<dp[i][j]<<" ";
		}//cout<<endl;
	}
	cout<<dp[0][0];
}