class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>pre(102,0);
        int points=0;

        for(auto & i :nums){
            pre[i[0]]++;
            pre[i[1]+1]--;
        }
          int cur=0;

          for(int i=1;i<=100;i++){
            cur+=pre[i];
            if(cur>0){
                points++;
            }
          }
          return points;
    }
};