class Solution {
public:
void dfs(int row ,int col,vector<vector<int>>& grid,vector<vector<bool>> &vis, int delrow[],int delcol[] ){
    vis[row][col]=true;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0 ; i<4 ; i++){
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
            dfs(nrow,ncol,grid,vis,delrow,delcol);

        }
        }


}
    int numEnclaves(vector<vector<int>>& grid) {
        int enclave=0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int j=0 ; j<m ; j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(0,j,grid,vis,delrow,delcol);
            }
        }
         for(int i=0 ; i<n ; i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,grid,vis,delrow,delcol);
            }
        }
         for(int j=0 ; j<m ; j++){
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                dfs(n-1,j,grid,vis,delrow,delcol);
            }
        }
         for(int i=0 ; i<n ; i++){
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,grid,vis,delrow,delcol);
            }
        }
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    enclave++;
                }
            }
        }
        return enclave;
    }
};