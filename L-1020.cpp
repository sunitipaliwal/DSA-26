class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }

        int delR[]={-1,0,+1,0};
        int delC[]={0,1,0,-1};
        while(!q.empty()){
            int r= q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr= r+delR[i];
                int nc= c+delC[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && 
                grid[nr][nc]==1 ){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                } 
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};