class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,long long>mpp;
        int n=nums.size();
        int i=0;
        int j=0;
       long long pairs=0;
       long long ans=0;

        while(j<nums.size()){
            pairs += mpp[nums[j]];
                mpp[nums[j]]++;


             while(pairs>=k){
                mpp[nums[i]]--;
               pairs -= mpp[nums[i]];
                i++;
             }
             ans+=i;
             j++;
        }
        return  ans;

    }
};