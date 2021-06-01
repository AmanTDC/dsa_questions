// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
	public:
	int gcd (int a,int b){
	    if( b == 0 )
	        return a;
	    return gcd(b,a%b);
	}
	int minSteps(int m, int n, int d)
	{
	    int jug1=0,jug2=0;
	int cnt = 0;
	
	if(d%gcd(m,n)!=0)
	return -1;
	while(cnt<m*n){
		if(jug1==d||jug2==d)
			break;
		else if(jug2==0)
			jug2 = n,cnt++;
		else if(jug1<m){
			int temp;
			jug1 += temp = min(m-jug1,jug2);
			jug2 = jug2-temp;
			cnt++;
		}
		else if(jug1 == m)
			jug1 = 0,cnt++;
	}
	jug1 = 0,jug2=0;
	int cnt2 = 0;
	while(cnt2<m*n){
		if(jug1==d||jug2==d)
			break;
		else if(jug1==0)
			jug1 = m,cnt2++;
		else if(jug2<n){
			int temp;
			jug2 += temp = min(n-jug2,jug1);
			jug1 = jug1-temp;
			cnt2++;
		}
		else if(jug2 == n)
			jug2 = 0,cnt2++;

	}
	
	return min(cnt2,cnt)!=m*n?min(cnt2,cnt):-1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends