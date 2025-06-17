class Solution {
public:
     
    int characterReplacement(string s, int k) {
      vector<int>freq(26,0);
      int n=s.size();
      int left=0;
      int result=0;
      int maxcount=0;
      for(int right=0;right<n;right++){
         freq[s[right]-'A']++;
         maxcount=max(maxcount,freq[s[right]-'A']);
         while((right-left+1)-maxcount>k){
            freq[s[left]-'A']--;
            left++;
         }
         result=max(result,right-left+1);
      }
      return result;
    }
};