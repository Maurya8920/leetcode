class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int row= pq.top().second.first;
            int col =  pq.top().second.second;
            pq.pop();
            for(int i =0 ; i<4 ; i++){
                int nrow=row+delrow[i];
                int ncol= col+delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int neweffort=max(dis,abs(heights[row][col]-heights[nrow][ncol]));
                    if(neweffort<dist[nrow][ncol]){
                    dist[nrow][ncol]=neweffort;
                    pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }


            }
        }
       return dist[n-1][m-1];
        
    }
};