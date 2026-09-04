class Solution {
    
public:

 void bfs(vector<vector<int>>&visited,vector<vector<int>>&grid,queue<pair<int,int>>&q,int n,int m,vector<vector<int>>&dist){

     vector<int>dx={-1,1,0,0};
     vector<int>dy={0,0,-1,1};
        while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;

                q.pop();

            for(int i=0;i<4;i++){

                int nr=x+dx[i];
                int nc=y+dy[i];

                if((nr>=0&&nr<n)&&(nc>=0&&nc<m)){
                    
                    if(grid[nr][nc]>0&&visited[nr][nc]==0){
                        visited[nr][nc]=1;
                        dist[nr][nc]=dist[x][y]+1;
                        q.push({nr,nc});
                    }
                }
            }

        }


 }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m));

        queue<pair<int,int>>q;
        vector<vector<int>>dist(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    visited[i][j]=1;
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }

        bfs(visited,grid,q,n,m,dist);


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dist[i][j]==-1&&grid[i][j]>0) dist[i][j]=grid[i][j];
            }
        }

        grid=dist;


    }
};
