#include<bits/stdc++.h>
using namespace std;
bool interleaved(string str,string str1,string str2,int n,int n1,int n2){
	cout<<n<<" "<<n1<<" "<<n2<<endl;
	if(n1==-1&&n2==-1&&n==-1)
		return 1;
	if(n1<0&&n2<0)
		return  0;
	if(str[n]==str1[n1]||str[n]==str2[n2]){
		bool first,second;
		if(str[n]==str1[n1])
			first = interleaved(str,str1,str2,n-1,n1-1,n2);
		else
			second = interleaved(str,str1,str2,n-1,n1,n2-1);
		return first||second;
	}
	else return 0;
}
int main(){
	string str,str1,str2;
	str = "XXXXXXXXXXXXXXXXXXXXXXXXZY",str1="XXXXXXXXXXXXZ",str2="XXXXXXXXXXXXY";
	int n1 = str1.length();
	int n2 = str2.length();
	int n = str.length();
	cout<<interleaved(str,str1,str2,n-1,n1-1,n2-1);
	//cout<<endl<<n1<<" "<<n2;
}