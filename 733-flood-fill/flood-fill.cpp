class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int intialcolor= image[sr][sc];
        if (intialcolor == color) return image;
        int n = image.size();
        int m = image[0].size();
        int delrow []={-1,0,1,0};
        int delcol []={0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0 ; i<4 ; i++){
              int nrow = row+delrow[i];
              int ncol = col+delcol[i];
              if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==intialcolor){
                image[nrow][ncol]=color;
                q.push({nrow,ncol});
              }
                
            }
        }
        return image;
    }
};