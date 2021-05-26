#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> my_set;

int helper(pair<int,int> start,int target){
	if(target<=1)
		return target;
	int sum = helper(start,target-1);
	if(my_set.find({start.first-1,start.second})!=my_set.end()){
		sum += helper({start.first-1,start.second},target-1);
	}
	if(my_set.find({start.first+1,start.second})!=my_set.end()){
		sum += helper({start.first+1,start.second},target-1);
	}
	if(my_set.find({start.first,start.second-1})!=my_set.end()){
		sum += helper({start.first,start.second-1},target-1);
	}
	if(my_set.find({start.first,start.second+1})!=my_set.end()){
		sum += helper({start.first,start.second+1},target-1);
	}
	return sum;
}
int MNKP(int n){
	int sum = 0;
	for(auto cur : my_set){
		sum+=helper(cur,n);
	}
	return sum;
}
int main(){
	int n = 5;
	my_set = {
	{0,1},{1,0},{0,0},
		{1,1},{2,2},{1,2},
		{0,2},{2,1},{2,0},
		{3,1}
	};
	vector<pair<int,int>>vec = {

		{0,1},{1,0},{0,0},
		{1,1},{2,2},{1,2},
		{0,2},{2,1},{2,0},
		{3,1}	

	};

	map<pair<int,int>,int> my_map;
	for(int i=0;i<10;i++)
		my_map[vec[i]] = i;
	//cout<<MNKP(n);
	//cout<<helper({0,0},2);
	//dp approach start
	int dp[10][n+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<10;i++){
		dp[i][1] = 1;
	}
	//traversing each column first(bit tricky to read :) but the idea is to travel
	//each column first like dp[0][1] to dp[9][1]  )
	for(int i = 2;i<=n;i++){
		for(int j=0;j<10;j++){
			auto cur = vec[j];
			dp[j][i] = dp[j][i-1];
			if(my_map.find({cur.first+1,cur.second})!=my_map.end())
				dp[j][i]+=dp[my_map[{cur.first+1,cur.second}]][i-1];
			if(my_map.find({cur.first-1,cur.second})!=my_map.end())
				dp[j][i]+=dp[my_map[{cur.first-1,cur.second}]][i-1];
			if(my_map.find({cur.first,cur.second+1})!=my_map.end())
				dp[j][i]+=dp[my_map[{cur.first,cur.second+1}]][i-1];
			if(my_map.find({cur.first,cur.second-1})!=my_map.end())
				dp[j][i]+=dp[my_map[{cur.first,cur.second-1}]][i-1];

			//cout<<dp[j][i]<<" ";
		}//cout<<endl;
	}
	int res = 0;
	for(int i=0;i<10;i++)
		res+= dp[i][n];
	cout<<res;
}
/*
    0 1 2

0	1 2 3
1	4 5 6
2	7 8 9
3	* 0 #


*/