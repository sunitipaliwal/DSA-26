class Solution {
    private: 
    void dfs(int r, int c, vector<vector<int>>&ans,vector<vector<int>>& image,  int nclr, int delR[], int delC[], int iniclr ){
        ans[r][c]= nclr;
        int n=image.size();
        int m= image[0].size();
        for(int i=0;i<4;i++){
            int nr= r+delR[i];
            int nc= c+delC[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==iniclr && ans[nr][nc]!= nclr){
                dfs(nr,nc,ans,image,nclr,delR,delC, iniclr);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniclr= image[sr][sc];
        vector<vector<int>>ans= image;
        int delR[]= {-1,0,1,0};
        int delC[]={0,1,0,-1};
        dfs(sr,sc, ans , image, color, delR, delC,iniclr);
        return ans;
    }
};