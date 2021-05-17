// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Program for zig-zag conversion of array
	void swap(int *arr,int i,int j){
	    int t = arr[i];
	    arr[i] = arr[j];
	    arr[j] = t;
	}
	void zigZag(int arr[], int n) {
	    int small = 1;
	    for(int i=0;i<n-1;i++){
	        int j = i+1;
	        if(small*arr[j]<small*arr[i])
	            swap(arr,i,j);
	        small *= -1;
	    }
	    //return arr;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
