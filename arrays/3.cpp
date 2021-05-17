// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // Function to find the subarray with given sum k
    // arr: input array
    // n: size of array
    vector<int> subarraySum(int arr[], int n, int s){
        vector<int>res;
        int beg = 0;
        int end = 0;
        int sum = arr[0];
        while(s!=sum&&end<n&&beg<n){
            //cout<<sum<<endl;
            if(s>sum)
                sum += arr[++end];
            else if(s<sum){
                sum -= arr[beg++];
                if(beg>end)
                    sum +=arr[++end];
            }
                
            
        }
        //cout<<endl<<sum<<endl;
        if(s==sum){
            //cout<<"l";
            res.push_back(beg+1);
            res.push_back(end+1);
        }
        else
            res.push_back(-1);
        return res;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
