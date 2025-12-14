class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // Step 1: find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: if no pivot, reverse entire array
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: find next greater element
        for (int j = n - 1; j > index; j--) {
            if (nums[j] > nums[index]) {
                swap(nums[j], nums[index]);
                break;
            }
        }

        // Step 4: reverse suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};

