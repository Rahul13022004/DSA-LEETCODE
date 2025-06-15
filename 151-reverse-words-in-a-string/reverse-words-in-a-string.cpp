class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
    //     stringstream ss(s);
    //     string token;
    //     string result="";
    //     while(ss>>token){
    //         result=token+" "+result;
    //     }
    //     if(!result.empty() && result.back()==' '){
    //       result.pop_back();
    //     }
    //   return result;
    int i=0;
    int l=0;
    int r=0;
    reverse(s.begin(),s.end());
    while(i<n){
        while(i<n && s[i]!=' '){
            s[r++]=s[i++];
        }
        if(l<r){
            reverse(s.begin()+l,s.begin()+r);
            s[r]=' ';
            r++;
            l=r;
        }
        i++;
    }
    s=s.substr(0,r-1);
    return s;
    }
};