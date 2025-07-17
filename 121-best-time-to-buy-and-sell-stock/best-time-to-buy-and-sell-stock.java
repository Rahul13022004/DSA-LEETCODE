class Solution {
    public int maxProfit(int[] prices) {
        int ans=Integer.MIN_VALUE;
        int mini=Integer.MAX_VALUE;
        for(int it:prices){
            mini=Math.min(mini,it);
            ans=Math.max(ans,it-mini);
        }
        return ans;
    }
}