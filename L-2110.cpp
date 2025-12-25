class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        int i=0;
        
        long long cnt=0;
        for(int j=0;j<n;j++){
          if(j>0 && prices[j]!= prices[j-1]-1){
            i=j;
          }
          cnt+=j-i+1;
          
        }
        return cnt;
    }
};