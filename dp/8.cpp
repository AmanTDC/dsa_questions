#include<bits/stdc++.h>
using namespace std;

long long countFriendsPairings(long long  n) { 
        long long dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++)
            dp[i] = (dp[i-1] + (i-1)*dp[i-2])%1000000007;
        return dp[n];
    }
int main(){
	int n = 10000;
	cout<<countFriendsPairings(n);
}