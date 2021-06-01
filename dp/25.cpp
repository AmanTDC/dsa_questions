#include<bits/stdc++.h>
using namespace std;
int strings(int n){
	int string_ending_with_zero = 1;
	int string_ending_with_one = 1;
	for(int i=2;i<=n;i++){
		int temp = string_ending_with_zero;
		string_ending_with_zero = string_ending_with_zero + string_ending_with_one;
		string_ending_with_one = temp;
	}
	return string_ending_with_one+string_ending_with_zero;

}
int main(){
	int n = 4;
	cout<<strings(n);
}