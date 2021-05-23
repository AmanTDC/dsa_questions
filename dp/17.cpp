
/* Always remember if in recursion your code has 
	[i+1]or [j+1] instance you start fillling 
	array in opposite directions
*/
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>&a,pair<int,int>&b){
	if(a.first==b.first)
		return a.second<b.second;
	return a.first<b.first;
}
//considering level
int minCost(vector<pair<int,int>>&treeFreq, int level,int beg,int end){
	if(beg>end)
		return 0;
	if(beg==end)
		return level*treeFreq[beg].second;
	int min_=INT_MAX;
	for(int i=beg;i<=end;i++){
		min_ = min(min_,level*treeFreq[i].second+minCost(treeFreq,level+1,beg,i-1)+minCost(treeFreq,level+1,i+1,end));
	}
	return min_;
}

int arrSum(vector<pair<int,int>>&treeFreq,int beg,int end){
	int sum = 0;
	for(int i=beg;i<=end;i++)
		sum+=treeFreq[i].second;
	return sum;
}

//non considering level
int minCostN(vector<pair<int,int>>&treeFreq,int beg,int end){
	if(beg>end)
		return 0;
	if(beg==end)
		return treeFreq[beg].second;
	int min_ = INT_MAX;
	for(int i=beg;i<=end;i++){
		min_ = min(min_,minCostN(treeFreq,beg,i-1)+minCostN(treeFreq,i+1,end));
	}
	return arrSum(treeFreq,beg,end)+min_;
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
	vector<pair<int,int>> treeFreq(n);
	for(int i=0;i<n;i++)
		cin>>treeFreq[i].first;
	for(int i=0;i<n;i++)
		cin>>treeFreq[i].second;
	sort(treeFreq.begin(),treeFreq.end(),compare);	
	//cout<<minCostN(treeFreq,0,n-1);
	int sums[n+1][n+1];//Will storing sums in extra array helpful?
	memset(sums,0,sizeof(sums));

	//gather sums
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j)
				sums[i][j]=treeFreq[j-1].second;
			else{
				sums[i][j] = sums[i][j-1]+treeFreq[j-1].second;
			}
		}
	}

	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));

	//calculate results
	//Time complexity n^3
	//space complexity 2 * n^2
	//calculating sum in extra table won't affect complexity at all
	//it's better to go without extra table
	for(int i=n;i>=0;i--){
		for(int j=0;j<=n;j++){
			if(i==j)
				dp[i][j] = treeFreq[j-1].second;
			else if(i<j){
				int min_ = INT_MAX;
				for(int ind = i;ind<=j;ind++){
					min_ = min(min_,dp[i][ind-1]+dp[ind+1][j]);
				}
				dp[i][j] = sums[i][j] + min_;

			}//cout<<dp[i][j]<<"\t";
		}//cout<<endl;
	}
	cout<<dp[1][n]<<endl;
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<minCostN(treeFreq,i,j)<<"\t ";
		}cout<<endl;
	}*/
}