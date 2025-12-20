class Solution {
public:
    int bsearch(int i, vector<int>& nums,int k, vector<long>&pre){
      int target= nums[i];
      int l=0;
      int r=i;
      int ans=i;
      while(l<=r){
        int mid= l+(r-l)/2;
        long cnt= i-mid+1;
        long windowSum= cnt*target;
        long currSum= pre[i]-pre[mid]+nums[mid];
        int operations= windowSum-currSum;
        if(operations>k){
            l=mid+1;
        }
        else{
            ans=mid;
            r=mid-1;
        }
      }
      return i-ans+1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        int result=0;
        sort(nums.begin(), nums.end());
        vector<long>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]= nums[i]+pre[i-1];
        }
        
         for(int i=0;i<nums.size();i++){
             int freq= bsearch(i,nums,k, pre);
             result= max(result,freq);
         }
         return result;
    }
};