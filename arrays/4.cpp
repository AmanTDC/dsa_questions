// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int arrSum(long long a[],int n){
        int s = 0;
        for(int i=0;i<n;i++){
            s+=a[i];
        }
        return s;
    }
    int equilibriumPoint(long long a[], int n) {
        long long part2 = arrSum(a,n) - a[0];
        
        long long part1 = 0;
        int i=1;
        for(;i<n&&part1!=part2;i++){
            part1 += a[i-1];
            part2 -= a[i];
        }
        if(part1==part2)
            return i;
        else
            return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
