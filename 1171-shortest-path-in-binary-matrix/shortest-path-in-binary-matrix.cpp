class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
           if(grid[n-1][m-1]==1) return -1;
           if(grid[0][0]==1) return -1;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>> q;
        int delrow[]={-1,-1,-1,0,0,1,1,1};
        int delcol[]={-1,0,1,-1,1,-1,0,1};
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int dis = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                q.pop();
                if(row == n-1 && col == m-1)
    return dis;
                for(int i  =0 ; i<8 ; i++){
                    int nrow= row+delrow[i];
                    int ncol = col+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                        dist[nrow][ncol]=dis+1;
                        q.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
     
        return -1;

    }
};