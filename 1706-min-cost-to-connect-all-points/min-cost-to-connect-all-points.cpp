class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       pq.push({0,0});
       int sum=0;
       while(!pq.empty()){
        int cost= pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(vis[node]==true) continue;
        vis[node]=true;
        sum+=cost;
        for(int i = 0 ; i<n ; i++){
        int x1 = points[i][0];
        int y1= points[i][1];
        int x2= points[node][0];
        int y2=points[node][1];
        int price = abs(x1-x2)+abs(y1-y2);
        if(!vis[i]){
            pq.push({price,i});
            }
        }
            
        }
       
        return sum;
        }
};