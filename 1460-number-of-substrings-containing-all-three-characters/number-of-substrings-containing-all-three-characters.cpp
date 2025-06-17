class Solution {
public:
   bool hasAllChar(vector<int>&freq){
    return freq[0]>0 && freq[1]>0 && freq[2]>0;
   }
    int numberOfSubstrings(string s) {
        int n=s.length();
        int left=0;
        int total=0;
        vector<int>freq(3,0);
        for(int right=0;right<n;right++){
             freq[s[right]-'a']++;
         while(hasAllChar(freq)){
            total+=n-right;
            freq[s[left]-'a']--;
            left++;
         }
        }
        return total;
    }
};