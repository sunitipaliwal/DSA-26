class Solution {
public:
    int longestContinuousSubstring(string s) {
        string ans= "abcdefghijklmnopqrstuvwxyz";
        int i=0;
        int j=ans.find(s[i]);

        if (j == string::npos) j = 0;

        int l=0;
        int maxl=0;
        while(i<s.size() ){

           

           if(s[i]==ans[j]){
            i++;
            j++;
            l++;
            maxl= max(l,maxl);
           }
           else{
                l=0;
               
                j=ans.find(s[i]);
                if (j == string::npos) j = 0;  
           }
        }
        return maxl;
    }
};