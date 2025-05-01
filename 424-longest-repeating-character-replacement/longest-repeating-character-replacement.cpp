class Solution {
public:
     //Rahul
    int characterReplacement(string s, int k) {
        vector<int>count(26,0);
        int n=s.size();
        int left=0;
        int result=0;
        int maxCount=0;
        for(int right=0;right<n;right++){
            count[s[right]-'A']++;
            maxCount=max(maxCount,count[s[right]-'A']);
            
            // If the number of characters to change exceeds k, shrink the window
            while((right-left+1)-maxCount>k){
                count[s[left]-'A']--;
                left++;
            }
            result=max(result,right-left+1);
        }
        return result;
    }
};