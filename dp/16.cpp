bool compare(struct val a,struct val b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
/*You are required to complete this method*/
int maxChainLen(struct val p[],int n){
    sort(p,p+n,compare);
    int dp[n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        dp[i] = 1;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].second<p[j].first)
                dp[j] = max(dp[j],1+dp[i]);
        }
    }
    int max_ = INT_MIN;
    for(int i=0;i<n;i++)
        //cout<<dp[i]<<" ";
        max_ = max(max_,dp[i]);
    return max_;
}