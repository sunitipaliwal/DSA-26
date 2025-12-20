class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(),0);
        int target= total-x;
        if (target<0) return -1;
        int i=0;
        int l=-1;
        int sum= 0;
        for(int j=0;j<nums.size();j++){
         
         sum+=nums[j];
            while(sum>target){
                sum=sum-nums[i];
                i++;
            }
            if(sum==target){
                l=max(l, j-i+1);
            }
        }
        if (l == -1) return -1;
        return nums.size() - l;

    }
};