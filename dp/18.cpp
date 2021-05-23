int countMin(string str){
        int n = str.length();
        int dp[n+2][n+2];
        string s = str;
        memset(dp,0,sizeof(dp));
       for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(s[i-1]==s[j-1])
				dp[i][j] = 1+dp[i+1][j-1];
			else
				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);

		}
	}
        return n-dp[1][n];
    }