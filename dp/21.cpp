#include<bits/stdc++.h>
using namespace std;
bool match(string s1,string s2,int i){
	if(i>=s1.length())
		return 1;
	if(s1.length()-i<s2.length())
		return 0;
	for(int j=0; j<s2.length() ;j++){
		if(s1[i+j]!=s2[j])
			return 0;
	}
	return 1;
}
bool wordBreak(vector<string>arr,string str,int i){
	if(i>=str.length())
		return true;
	for(int j = 0;j<arr.size();j++){
		if(match(str,arr[j],i)&&wordBreak(arr,str,i+arr[j].length()))
			return true;
	}
	return false;
}
/// after using hashMap for faster dictionary checking
bool wordBreak_new(unordered_map<string,bool>&dict,string &str,int beg,int end){
	if(beg>=str.length()||end>=str.length())
		return true;
	for(int j=beg;j<=end;j++){
			if(dict[str.substr(beg,j-beg+1)]&&wordBreak_new(dict,str,j+1,end))
				return true;
	}
	return false;	
}
int main(){
	int n;

	vector<string>arr={ "samrat","sam","ratkhan"};
	unordered_map<string,bool>dict;
	for(string i : arr)
		dict[i] = true;
	string str="samratratkhan";
	n = str.length();
/*	cout<<wordBreak_new(dict,str,0,n-1);
	return 0;
	bool dp[n+1];
	memset(dp,0,sizeof(dp));
	for(int i=n;i>=0;i--){
		for(int j=0;j<arr.size();j++){
			if(match(str,arr[j],i))
				if(i+arr[j].length()>=n||dp[i+arr[j].length()]){
					dp[i] = 1;
					break;
				}
		}
	}
	for(int i=0;i<n;i++)
			cout<<dp[i]<<" ";
	cout<<endl<<dp[0];
*/

	//Optimized DP approach
	/*int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	
	for(int i=n;i>=0;i--){
		for(int j=0;j<n;j++){
			if(i>j)
				dp[i][j] = -1;
			else if(dict[str.substr(i,j-i+1)])
				dp[i][j] = 1;
			else{
				for(int k=i;k<=j;k++){
					
					if(dp[i][k]&&dp[k+1][j]){
						dp[i][j] = 1;
						break;
					}
				}
			}
			cout<<dp[i][j]<<"\t";
		}cout<<endl;
	}
	cout<<dp[0][n-1];*/

	//Most Optimized approach
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;

	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			//if(j==0)
			//cout<<dict[str.substr(j,i-j)];
			if(dp[j]&&dict[str.substr(j,i-j)]){
				dp[i] = 1;
				break;
			}
		}
		//cout<<dp[i]<<" ";
	}
	cout<<dp[n];

}