class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int m= roads.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0 ; i<m ; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v,wt});
             adj[v].push_back({u,wt});
        }
        vector<long long> dist(n,1e18);
        dist[0]=0;
        priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<long long> ways(n,0);
        ways[0]=1;
        const int MOD = 1e9+7;
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis>dist[node]) continue;
            for(auto it : adj[node]){
                int v = it.first;
                int wt =  it.second;
                if(dis+wt<dist[v]){
                    dist[v]=dis+wt;
                    ways[v]=ways[node];
                    pq.push({dis+wt,v});
                }
                else if(dis+wt==dist[v]){
                    ways[v]=(ways[v]+ways[node])%MOD;
                }
            }
        }
return ways[n-1];

    }
};