#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 11;
	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} ;
	int cnt = 0,i=0;
	while(i<n){
		if(cnt>10){
			cout<<"error";break;
		}
		cnt++;
		if(arr[i]+i>=n-1)
			break;
		int m = 0;
		for(int j=i+1;j<n&&j<=arr[i]+i;j++)
			if(arr[j]+j>=arr[m]+m)
				m=j;
		if(i==m)
			break;
		i=m;
	}
	cout<<cnt;

}