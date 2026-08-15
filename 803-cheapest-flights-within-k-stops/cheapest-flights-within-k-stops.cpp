class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
         if(src==dst) return 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
         vector<vector<pair<int,int>>> adj(n);
        for(int i =0 ; i<m ; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int price= flights[i][2];
            adj[u].push_back({v,price});
 }
        vector<vector<int>>dist(n,vector<int>(k+2,1e9));

         pq.push({0,{src,0}});
         dist[src][0]=0;
         while(!pq.empty()){
            int dis = pq.top().first;
            int node= pq.top().second.first;
            int stop=pq.top().second.second;
            pq.pop();
             if(stop==k+1){
             continue;
            }
            for(auto it : adj[node]){
                int v =it.first;
                int wt= it.second;
                if(dis+wt<dist[v][stop+1]){
                    dist[v][stop+1]=dis+wt;
                    pq.push({dist[v][stop+1],{v,stop+1}});
                }
                }
                  }
                  int ans = 1e9;
                  for(int i = 0 ; i<=k+1 ; i++){
                  ans=min(ans,dist[dst][i]);
                  }
                  if(ans==1e9) return -1;
    return ans;
        
    }
};