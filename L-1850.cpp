class Solution {
public:
      string nextPermutation(string nums, int k) {
        int n = nums.size();
       
          
        // Step 1: find pivot
        while(k--){
             int index = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: if no pivot, reverse entire array
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return nums;
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
        return nums;

    }

     
    int getMinSwaps(string num, int k) {
        string target= nextPermutation(num,k);
        int swaps=0;
         for (int i = 0; i < num.size(); i++) {
            if (num[i] == target[i]) continue;

            int j = i;
            while (num[j] != target[i]) j++;

           
            while (j > i) {
                swap(num[j], num[j - 1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};