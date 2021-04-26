#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll helper(ll *arr,ll n,ll k){
    ll msf = 0;
    ll max_ = INT_MIN;
    for(int i=0;i<n*k;i++){
        msf += arr[i%n];
        max_ = max(max_,msf);
        if(msf<0)
            msf = 0;
    }
    return max_;
}
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        
        ll arr[n],sum = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        ll m1 = helper(arr,n,1);
        ll m2 = INT_MIN;
        ll diff = 0;
        if(k>1){
            m2 = helper(arr,n,2);
            diff = m2 - sum*2;
        }
        
        //cout<<"diff-"<<m1<<" "<<m2<<endl;
        
        
        if(sum*k <= max(m1,m2)){
            cout<< max(m1,m2)<<endl;
            continue;
        }
        else if(diff>=0){
            cout<<sum*k + diff<<endl;
            continue;
        }
    }
}
