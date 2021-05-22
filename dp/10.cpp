#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	#ifndef ONLINE_JUDGE	
	    // for getting input from input.txt
	    freopen("inputf.in", "r", stdin);
	    // for writing output to output.txt
	    freopen("outputf.in", "w", stdout);
	#endif
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int mis[n],mds[n];
	for(int i=0;i<n;i++){
		mis[i] = arr[i];
		mds[i] = arr[i];
	}

	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]<arr[j])
				mis[j] = max(mis[j],mis[i]+arr[j]);
		}
	}
	for(int i=n-1;i>=1;i--){
		for(int j=i-1;j>=0;j--){
			if(arr[i]<arr[j])
				mds[j] = max(mds[j],mds[i]+arr[j]);
		}
	}
	int res = INT_MIN;
	for(int i=0;i<n;i++){
		res = max(res,mis[i]+mds[i]-arr[i]);
		//cout<<mis[i]<<" ";
	}
	cout<<res;

}