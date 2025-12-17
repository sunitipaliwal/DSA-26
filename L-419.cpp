class Solution {
    private:
   void dfs(int r ,int c, vector<vector<char>>& board , vector<vector<bool>>& vis, int delR[], int delC[]){
           int n= board.size();
           int m= board[0].size();
           vis[r][c]= true;

           for(int k=0;k<4;k++){
            int nr = r+delR[k];
            int nc= c+ delC[k];
              if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='X' && !vis[nr][nc]){
                dfs(nr, nc , board, vis, delR, delC);
              }
           
           }
           
           
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
           int n= board.size();
           int m= board[0].size();
vector<vector<bool>>vis(n, vector<bool>(m,false));
        int delR[]= {-1,0,1,0};
        int delC[]={0,1,0,-1};
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(board[i][j]=='X' && !vis[i][j]){
                    ans++;
                    dfs(i,j,board, vis, delR,delC);
                 }
            }
        }
        return ans;
    }
};