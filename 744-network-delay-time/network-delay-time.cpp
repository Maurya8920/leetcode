class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0 ; i<m ; i++){
            int u = times[i][0];
            int v= times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        queue<pair<int,int>> q;
        q.push({0,k});
        while(!q.empty()){
            int dis = q.front().first;
            int node = q.front().second;
            q.pop();
        for(auto it : adj[node]){
            int v = it.first;
            int wt =  it.second;
            if(dis+wt<dist[v]){
                dist[v]=dis+wt;
                q.push({dis+wt,v});
            }
        }
        }
        int ans = INT_MIN;
        for(int i = 1 ; i<dist.size() ; i++){
            if(dist[i]==1e9) return -1;
            ans=max(ans,dist[i]);

        }
        return ans;
    }
};