class Solution {
    private:
    void dfs( int r, int c, vector<vector<int>> &vis, vector<vector<char>>mat, int delR[], int delC[]){
        int n= mat.size();
        int m= mat[0].size();
   vis[r][c]=1;
  for(int i=0;i<4;i++){
    int nr= r+delR[i];
    int nc= c+delC[i];
    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc]=='O'){
        dfs(r,c, vis,mat,delR, delC);
    }
  }
    }
   
public:

 vector<vector<char>>fill(int n, int m, vector<vector<char>>mat){

    int delR[]= {-1,0,1,0};
    int delC[]={0,1,0,-1};
        vector<vector<int>>vis(n, vector<int>(m,0));

        for(int j=0;j<m;j++){
            if(!vis[0][j]&& mat[0][j]=='O'){
                dfs(0, j, vis,mat, delR, delC);
            }
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1, j, vis,mat, delR, delC);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,vis,mat,delR, delC);
            }
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat, delR, delC);
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }

    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m=board[0].size();
        board= fill(n,m,board);
        return;
    }
};