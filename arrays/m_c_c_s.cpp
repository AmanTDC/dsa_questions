#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadane(int arr[],int num){
        int max_ = INT_MIN;
        int msf = 0;
        for(int i=0;i<num;i++){
            msf += arr[i];
            max_ = max(max_,msf);
            msf = max(0,msf);
        }
        return max_;
    }
    int circularSubarraySum(int arr[], int num){
        int non_circular  = kadane(arr,num);
        if(non_circular<0){
            return non_circular;
        }
        int arr_sum = 0;
        for(int i=0;i<num;i++){
            arr_sum+=arr[i];
            arr[i]=-arr[i];
        }
        int min_subarray = kadane(arr,num);
        if(non_circular>=min_subarray+arr_sum)
            return non_circular;
        else
            return min_subarray + arr_sum ;
        
            
        
        // your code here
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
