class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
         if(src==dst) return 0;
         vector<vector<pair<int,int>>> adj(n);
        for(int i =0 ; i<m ; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int price= flights[i][2];
            adj[u].push_back({v,price});
 }
        vector<int> dist(n,1e9);
      
        queue<pair<int,pair<int,int>>> q;
        // stop,node,distance in queue
         q.push({0,{src,0}});
           dist[src]=0;
         while(!q.empty()){
            int stop = q.front().first;
            int node= q.front().second.first;
            int dis=q.front().second.second;
            q.pop();
             if(stop>k){
             continue;
            }
            for(auto it : adj[node]){
                int v =it.first;
                int wt= it.second;
                if(dis+wt<dist[v] && stop<=k){
                    dist[v]=dis+wt;
                    q.push({stop+1,{v,dis+wt}});
                }
                }
                  }
                  
                  if(dist[dst]==1e9) return -1;
    return dist[dst];
        
    }
};