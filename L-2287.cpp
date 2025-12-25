class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int>mpp, mpp2;
         int c=INT_MAX;
        for(char ch:s){
            mpp[ch]++;
        }
        for(char ch:target){
            mpp2[ch]++;

        }
        for(auto &it: mpp2){
            char ch= it.first;
            int need= it.second;
            if(mpp[ch]==0)
            return 0;
            c= min(c,mpp[ch]/need);
        }
        
        return c;
    }
};