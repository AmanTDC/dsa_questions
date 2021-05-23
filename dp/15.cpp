// sort by area.. and ensure w>d
//Tricky question lis variation
#include<bits/stdc++.h>
using namespace std;
class Box{
public:
	int h;
	int w;
	int d;
	
};
bool compare(Box a,Box b){
	// if(a.w*a.d==b.w*b.d)
	// 	return a.w<b.w;
	return a.w*a.d<b.w*b.d;
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

	vector<Box>arr(3*n);
	for(int i=0;i<n;i++)
		cin>>arr[i].h;
	for(int i=0;i<n;i++)
		cin>>arr[i].w;
	for(int i=0;i<n;i++)
		cin>>arr[i].d;

	for(int i=n;i<n*2;i++){
		arr[i].h=arr[i-n].w;
		arr[i].w=max(arr[i-n].h,arr[i-n].d);
		arr[i].d=min(arr[i-n].h,arr[i-n].d);

		arr[n+i].h=arr[i-n].d;
		arr[n+i].w=max(arr[i-n].h,arr[i-n].w);
		arr[n+i].d=min(arr[i-n].h,arr[i-n].w);

		if(arr[i-n].w<arr[i-n].d){
			int t = arr[i-n].w;
			arr[i-n].w = arr[i-n].d;
			arr[i-n].d = t;
		}
	}
	n=3*n;
	sort(arr.begin(),arr.end(),compare);
		
	int dp[n];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		dp[i] = arr[i].h;
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if( arr[i].w<arr[j].w&&arr[i].d<arr[j].d)
				dp[j] = max(dp[j],dp[i]+arr[j].h);
		}
	}
	int max_ = INT_MIN;
	for(int i=0;i<n;i++){
		max_ = max(max_,dp[i]);
	}
	
	cout<<max_;
}