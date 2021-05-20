//priority queue solution
ull getNthUglyNo_1(int n) {
	    priority_queue<ull, vector<ull>, greater<ull> >pq;
	    map<ull,bool>hash;
	    pq.push(1);
	    ull cnt =0;
	    while(cnt<n){
	        ull cur = pq.top();
	        pq.pop();
	        cnt++;
	        
	        if(cnt==n)
	            return cur;
	            
	       if(hash[cur*2]==0)
	        pq.push(cur*2),hash[cur*2]=1;
	        
	       if(hash[cur*3]==0)
	        pq.push(cur*3),hash[cur*3]=1;
	        
	       if(hash[cur*5]==0)
	        pq.push(cur*5),hash[cur*5]=1;
	        
	    }
	    return 1;
	}

//Dp solution 
ull getNthUglyNo(int n) {
	   
	    ull arr[n+1];
	    int end = -1;
	    arr[++end] = 1;
	    
	    int i2 = 0,i3=0,i5=0;
	    ull cnt  =1;
	    while(end<n-1){
	        ull m = min(min(arr[i2]*2,arr[i3]*3),arr[i5]*5);
	        if(m!=arr[end])
	            arr[++end]=m;
	        
	        if(m==arr[i2]*2)
	            i2++;
	            
	        else if(m==arr[i3]*3)
	            i3++;
	            
	        else
	            i5++;
	            
	        
	    }
	    return arr[n-1];
	
	}