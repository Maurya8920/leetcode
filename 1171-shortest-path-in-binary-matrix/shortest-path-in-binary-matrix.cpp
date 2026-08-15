class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
           if(grid[n-1][m-1]==1) return -1;
           if(grid[0][0]==1) return -1;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        int delrow[]={-1,-1,-1,0,0,1,1,1};
        int delcol[]={-1,0,1,-1,1,-1,0,1};
        q.push({0,0});
        vis[0][0]=true;
        int count=1;
        while(!q.empty()){
            int size=q.size();
            for(int i = 0 ; i<size; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if(row==n-1 && col==m-1) return count;
                for(int i  =0 ; i<8 ; i++){
                    int nrow= row+delrow[i];
                    int ncol = col+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && !vis[nrow][ncol]){
                        vis[nrow][ncol]=true;
                        q.push({nrow,ncol});
                    }
                }
            }
            count++;
           
        }
     
        return -1;

    }
};