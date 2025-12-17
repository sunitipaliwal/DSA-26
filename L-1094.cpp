class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>pre(1001, 0);

        for(auto &it : trips){
            pre[it[1]]+= it[0];
            pre[it[2]]-= it[0];
        }
           int c=0;
        for(int i=0;i<1001;i++){
          c+=pre[i];
          if(c>capacity)
          return false;
           
        }
        return true;
    }
};