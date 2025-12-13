 int n=coins.size();
        long long INF = 1e15;
vector<vector<long long>> t(n+1, vector<long long>(amount+1, INF));

        for(int i=1;i<=n;i++){
            t[i][0]=0;
        }
        for(int j=1; j<=amount;j++){
            if(j%coins[0]==0){
                t[1][j]=j/coins[0];
            }
            else{
                t[1][j]=INF;
            }
        }
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    t[i][j]= min(1+ t[i][j-coins[i-1]],  t[i-1][j]);
                }
            
            else{
                t[i][j]= t[i-1][j];
            }
            }
        }
        return (t[n][amount] ==INF)? -1 :(int)t[n][amount];