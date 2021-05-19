#include<bits/stdc++.h>
using namespace std;
void primeFactors(int n){
	if(n==1)
		return ;
	int prime[n+1];
	for(int i=0;i<=n;i++)
		prime[i] = 1;
	
	for(int i=2;i*i<=n;i++){
		if(prime[i]==1){
			for(int j=i*i;j<=n;j+=i){
				if(prime[j]==1)
					prime[j] = i;
			}
		}
	}
	while(prime[n]!=1){
		cout<<prime[n]<<" ";
		n/=prime[n];
	}
	cout<<n;
	
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
	primeFactors(9999);
}