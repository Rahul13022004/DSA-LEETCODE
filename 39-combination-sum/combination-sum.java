class Solution {
    public void solve(int i,int sum,int n,int[] candidates,int target,List<Integer>temp,List<List<Integer>>ans){
        if(i>=n){
            if(sum==target){
                ans.add(new ArrayList<>(temp));
            }
            return;
        }
       // Include current number (if it doesn't exceed target)
        if (sum + candidates[i] <= target) {
            temp.add(candidates[i]);
            // stay at same i to allow reuse
            solve(i, sum + candidates[i], n, candidates, target, temp, ans);
            temp.remove(temp.size() - 1);
        }

        solve(i+1,sum,n,candidates,target,temp,ans);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        int n=candidates.length;
        List<List<Integer>>ans=new ArrayList<>();
        List<Integer>temp=new ArrayList<>();
        solve(0,0,n,candidates,target,temp,ans);
        return ans;
    }
}