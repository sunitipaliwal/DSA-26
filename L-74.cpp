class Solution {
public:
    bool binarySearch(vector<int> &nums,int target)
    {
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]<target)
            start=mid+1;
            else if(nums[mid]==target)
            return true;
            else
            end=mid-1;
        }
        return false;

        }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0) return false;
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && target<=matrix[i][m-1]){
                return binarySearch(matrix[i],target);
            }
        }
            return false;
    }
};


 //lets do the approach nmumber two
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     //applying binary search
    //     int low=0;
    //     int high=(m*n)-1;   //size minus one basically
    //     while(low<=high){
    //         int mid=(low+high)/2;
    //         int row=mid/m;
    //         int col=mid%m;
    //         if(matrix[row][col]==target)
    //             return true;
    //          else if(matrix[row][col]<target)
    //          low=mid+1;
    //          else high=mid-1;   
    //     }
    //     return false;
       
    // }