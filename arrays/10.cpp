// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        int max_height = 0;
        int area =0;
        int max_i = 0;
        for(int i=0;i<n;i++){
            if(arr[max_i]<=arr[i])
                max_i  = i;
        }
        //return max_i;
        int cur_max = 0;
        int cur_top = 0;
        
        while(cur_top<max_i){
            
            if(arr[cur_top]>arr[cur_max])
                cur_max=cur_top;
                
            area += arr[cur_max] - arr[cur_top];
            cur_top++;
        }
        //cout<<area<<" ";
        cur_max = n-1;
        cur_top = n-1;
        while(cur_top>max_i){
            
            if(arr[cur_top]>arr[cur_max])
                cur_max=cur_top;
                
            area += arr[cur_max] - arr[cur_top];
            cur_top--;
        }//cout<<area<<" ";
        return area;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
