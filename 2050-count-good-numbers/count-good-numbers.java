class Solution {
    final int MOD=1_000_000_007;
    long myPow(long base,long exp){
        long result=1;
        while(exp>0){
            if((exp&1)==1){
                result=(result*base)%MOD;
            }
            base=(base*base)%MOD;
            exp>>=1;
        }
        return result;
    }
    public int countGoodNumbers(long n) {
        long evenpositions=(n+1)>>1;
        long oddpositions=n>>1;
        long res=(myPow(5,evenpositions)*myPow(4,oddpositions))%MOD;
        return (int)res;
    }
}