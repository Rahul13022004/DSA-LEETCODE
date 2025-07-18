class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length())return false;
        Map<Character,Integer> s_to_t= new HashMap<>();
        Map<Character,Integer> t_to_s= new HashMap<>();
        for(int i=0;i<s.length();i++){
            if(!s_to_t.containsKey(s.charAt(i))){
                s_to_t.put(s.charAt(i),i);
            }
            if(!t_to_s.containsKey(t.charAt(i))){
                t_to_s.put(t.charAt(i),i);
            }
            if(s_to_t.get(s.charAt(i))!=t_to_s.get(t.charAt(i))){
                return false;
            }
        }
      return true;
    }
}