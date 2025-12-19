class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            int n= nums.size();
           if(k<=1) return 0; 

            int i=0;
            int c=0;
            int pro=1;
           for(int j=0;j<n;j++){

            
              pro=pro*nums[j];

             while(pro>=k){
                pro/=nums[i];
                i++;
              }
              c+=j-i+1;
              
           }
           return c;
    }
};  