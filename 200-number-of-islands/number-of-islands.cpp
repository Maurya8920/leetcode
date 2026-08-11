class Solution {
public:
void dfs(int row ,int col ,vector<vector<char>>& grid , vector<vector<bool>> &vis,int delrow[],int delcol[]){
    vis[row][col]=true;
    int n= grid.size();
    int m =grid[0].size();
for(int i = 0 ;i<4; i++ ){
    int nrow= row+delrow[i];
    int ncol=col+delcol[i];
if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'&&!vis[nrow][ncol]){
            dfs(nrow,ncol,grid,vis,delrow,delcol);
        }
 }

}
 int numIslands(vector<vector<char>>& grid) {
    int cnt=0;
    int n = grid.size();
    int m = grid[0].size();
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};

    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i = 0 ; i<n ; i++){
        for(int j  = 0 ; j<m; j++){
             if(grid[i][j]=='1'&& !vis[i][j]){
            cnt++;
            dfs(i,j,grid,vis,delrow,delcol);

        }
    }

    }
return cnt;
        
    }
};