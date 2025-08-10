class Solution {
    public double myPow(double x, int n) {
        if(n==0)return 1;
        long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        if(N%2==1){
             return x*myPow(x*x,(int)((N-1)>>1));
        }else{
            return myPow(x*x,(int)(N>>1));
        }
    }
}