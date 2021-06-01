#include<bits/stdc++.h>
using namespace std;
int boardSize;
bool inside(int x,int y){
	if(x>=0&&x<boardSize&&y>=0&&y<boardSize)
		return 1;
	return 0;
}
double knightProb(int x,int y,int k){
	if(!inside(x,y))
		return 0;
	if(k==0)
		return 1;
	double prob = 0;
	if(inside(2+x,y+1))
		prob+=knightProb(2+x,y+1,k-1);
	if(inside(2+x,y-1))
		prob+=knightProb(x+2,y-1,k-1);
	if(inside(x-2,y+1))
		prob+=knightProb(x-2,y+1,k-1);
	if(inside(x-2,y-1))
		prob+=knightProb(x-2,y-1,k-1);
	if(inside(x+1,y+2))
		prob+=knightProb(x+1,y+2,k-1);
	if(inside(x-1,y+2))
		prob+=knightProb(x-1,y+2,k-1);
	if(inside(x+1,y-2))
		prob+=knightProb(x+1,y-2,k-1);
	if(inside(x-1,y-2))
		prob+=knightProb(x-1,y-2,k-1);
	return prob/8.0;
}
int main(){
	int x=0,y=0;
	int k=4;
	boardSize = 4;
	//cout<<knightProb(x,y,k);
	
	//optimized
	double dp[k+1][boardSize][boardSize];
	for(int steps = 0;steps<=k;steps++){
		for(int x = 0;x<boardSize;x++){
			for(int y=0;y<boardSize;y++){
				if(steps==0)
					dp[steps][x][y] = 1;
				else{
					double prob = 0;
					if(inside(2+x,y+1))
						prob+=dp[steps-1][2+x][y+1];
					if(inside(2+x,y-1))
						prob+=dp[steps-1][x+2][y-1];
					if(inside(x-2,y+1))
						prob+=dp[steps-1][x-2][y+1];
					if(inside(x-2,y-1))
						prob+=dp[steps-1][x-2][y-1];
					if(inside(x+1,y+2))
						prob+=dp[steps-1][x+1][y+2];
					if(inside(x-1,y+2))
						prob+=dp[steps-1][x-1][y+2];
					if(inside(x+1,y-2))
						prob+=dp[steps-1][x+1][y-2];
					if(inside(x-1,y-2))
						prob+=dp[steps-1][x-1][y-2];//k-1);
					dp[steps][x][y] = prob/8.0;
				}
			}
		}
	}
	cout<<dp[k][x][y];

}
