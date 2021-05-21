int LongestBitonicSequence(vector<int>nums){
	    int n = nums.size();
	    vector<int>lis,lds;
	    for(int i:nums){
	        lis.push_back(1);
	        lds.push_back(1);
	    }
	    
	    for(int i=0;i<n-1;i++)
	        for(int j=i+1;j<n;j++)
	            if(nums[i]<nums[j])
	                lis[j] = max(lis[j],lis[i]+1);
	    for(int i=n-1;i>=1;i--)
	        for(int j=i-1;j>=0;j--)
	            if(nums[i]<nums[j])
	                lds[j] = max(lds[j],lds[i]+1);
	   
	   int res = 1;
	    for(int i=0;i<n;i++){
	       res = max(res,lds[i]+lis[i]-1);
	    }
	    return res;
	}   