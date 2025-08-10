class Solution {
    public void solve(int i,int n,int[] nums,List<Integer>temp,List<List<Integer>>ans){
        if(i==n){
            ans.add(new ArrayList<>(temp));
            return;
        }
        temp.add(nums[i]);
        solve(i+1,n,nums,temp,ans);
        temp.remove(temp.size()-1);
        solve(i+1,n,nums,temp,ans);
    }
    public List<List<Integer>> subsets(int[] nums) {
        int n=nums.length;
        List<List<Integer>>ans=new ArrayList<>();
        List<Integer>temp=new ArrayList<>();
        solve(0,n,nums,temp,ans);
        return ans;

    }
}