class Solution {
public:
   int count(int x, vector<int>& nums ){
           int cnt=0;
           int i=0;
           for(int j=0;j<nums.size();j++){
              if(nums[j]>x){
                i=j+1;
              }
              cnt+= j-i+1;
           }
           return cnt;
     }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
       return count(right, nums)- count(left-1,nums);
    }

};