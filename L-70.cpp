class Solution {
public:
    int climbStairs(int n) {
        if(n<0){
            return 0;
        }
        if(n==0 || n==1){
            return 1;
        }
        vector<int>t(n+1);
        t[0]=1;
         t[1] = 1;
        for(int i=2;i<=n;i++){
            t[i]=t[i-1]+t[i-2];
        }
        return t[n];
    }
};