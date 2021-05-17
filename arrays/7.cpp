// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends

bool bsearch_(int *arr,int left,int right,int n){
    while(left<=right){
        int mid = left+right;
        mid/=2;
        
        if(arr[mid]==n)
            return 1;
        else if(arr[mid]>n){
            right = mid-1;
        }
        else
            left = mid + 1; 
    }
    return 0;
}

bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    int i=0;
    int j=1;
    while(i<=j&&i<size&&j<size){
        int cur_diff = arr[j]-arr[i];
        if(cur_diff==n)
            return 1;
        if(n>cur_diff)
            j++;
        else
            i++;
            
        
    }
    return 0;
    
}
