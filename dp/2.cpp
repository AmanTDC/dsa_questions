#include<bits/stdc++.h>
using namespace std;
int main(){
	int primes[] = {2, 3,7, 11,13};
	int len = 5;
	int n = 40;
	vector<int>res;
	int i_s[len];
	memset(i_s,0,sizeof(i_s));
	res.push_back(1);
	while(res.size()<n){
		int m = INT_MAX;
		int cur_p;
		for(int i=0;i<len;i++){
			int temp = primes[i]*res[i_s[i]];
			if(temp<m){
				m=temp;
				cur_p = i;
			}

		}
		i_s[cur_p]++;
		if(m!=res[res.size()-1])
			res.push_back(m);

	}

	cout<<res[n-1];
}