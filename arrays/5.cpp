// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int dp[1001];
	int maxSumIS(int arr[], int n)  
	{  
	      
	      dp[0] = arr[0];
	      
	      for(int i=1;i<n;i++){
	          dp[i] = arr[i];
	          int temp = arr[i];
	          for(int j=0;j<i;j++){
	              if(arr[j]<arr[i]){
	                  dp[i] = max(dp[i],dp[j]+temp);
	              }
	          }
	      }
	      int max_=INT_MIN;
	      for(int i=0;i<n;i++)
	      max_=max(max_,dp[i]);
	      return max_;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
