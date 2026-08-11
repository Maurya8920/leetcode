class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int n= grid.size();
        int m = grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        queue<pair<int,int>>q;
        for(int i = 0 ; i<n ; i++){
            for(int j= 0 ; j<m ; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        int min=0;
        
        while(!q.empty()){
            int size=q.size();
            bool rotten=false;
            for(int i = 0 ; i<size ; i++){
            int row= q.front().first;
            int col =  q.front().second;
            q.pop();
            for(int j = 0 ; j<4 ; j++){
                int nrow = row+delrow[j];
                int ncol = col+delcol[j];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 ){
                    count--;
                    grid[nrow][ncol]=2;
                    q.push({nrow,ncol});
                    rotten=true;
                    }
                }
            }
            if(rotten==true)
                min++;
            }
        if(count==0) return min;
        if(count>0){
            return -1;
        }
        return min;
    }
};