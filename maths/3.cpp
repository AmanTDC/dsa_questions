class Solution {
  public:
    long long maximizeEulerRatio(long long N) {
        long long copy = N;
        long long divisor = 2;
        double res = N;
        while(copy>1){
            if(copy%divisor==0){
                res*=(1.0-1.0/(double)divisor);
                
                
                while(copy%divisor==0)
                    copy/=divisor;    
                continue;
            }
            divisor++;
        }
        return (long long)round(res);
    }
};