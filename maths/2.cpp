#include<bits/stdc++.h>
using namespace std;

void product(int mat1[][2], int mat2[][2] , int n){
	int mat3[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mat3[i][j] = 0;
			for(int k=0;k<n;k++){
				mat3[i][j] += mat1[i][k]*mat2[k][j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			mat1[i][j]=mat3[i][j];
	}
}
void power(int mat[][2],int k){
	int res[][2] = {{1,0},{0,1}};
	while(k>0){
		if(k%2==1)
			product(res,mat,2);
		k = k/2;
		product(mat,mat,2);
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
			mat[i][j]=res[i][j];
	}
}

int main(){
	#ifndef ONLINE_JUDGE	
	    // for getting input from input.txt
	    freopen("inputf.in", "r", stdin);
	    // for writing output to output.txt
	    freopen("outputf.in", "w", stdout);
	#endif

	   int n;
	   cin>>n;

	   int m[][2] = {{1,1},{1,0},{0,0}};
	   power(m,n-1);

	   cout<<m[0][0];


}