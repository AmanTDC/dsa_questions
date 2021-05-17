// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C


//Function to rotate matrix anticlockwise by 90 degrees.
void rotateby90(int n, int matrix[][n]) 
{   
    //flip the matrix along i==j diagonal
    for(int i=0; i<n;i++){
        for(int j=i+1;j<n;j++){
            int t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
    //flip along horizontal axis
    for(int i=0;i<n;i++){
        for(int j=0,k=n-1;j<k;j++,k--){
            int t = matrix[j][i];
            matrix[j][i] = matrix[k][i];
            matrix[k][i] = t;
        }
    }
    
} 

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		int matrix[n][n];
	 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		
		rotateby90(n, matrix);
		for(int i = 0; i < n; i++)
		    for(int j=0; j<n; j++)
			    printf("%d ", matrix[i][j]);
		printf("\n");
	}
	return 0;
}  // } Driver Code Ends
