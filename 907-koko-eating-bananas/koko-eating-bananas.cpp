class Solution {
public:
    bool canEat(int k,int h,vector<int>&piles){
        long long totalhrs=0;
        for(int i=0;i<piles.size();i++){
             totalhrs+=piles[i]/k;
             if(piles[i]%k!=0){
                totalhrs++;
             }
        }
        return totalhrs<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.empty())return 0;
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canEat(mid,h,piles)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};