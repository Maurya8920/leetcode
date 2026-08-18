class Solution {
public:
int time =0;
void dfs(int src ,int parU, vector<vector<int>> & adj , vector<bool> &vis , vector<int> &distime,vector<int> &lowtime , vector<vector<int>> & bridges){
    vis[src]=true;
    distime[src]=lowtime[src]=time++;
    for(auto v : adj[src]){
        if(!vis[v]){
            dfs(v,src,adj,vis,distime,lowtime,bridges);
            lowtime[src]=min(lowtime[src],lowtime[v]);

            if(lowtime[v]>distime[src]){
                bridges.push_back({src,v});
            }
        }
            else if (v!=parU){
                lowtime[src]=min(lowtime[src],distime[v]);
            }
        
    }
}

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        vector<int> distime(n);
        vector<int> lowtime(n);
        vector<vector<int>> bridges;
        dfs(0,-1,adj,vis,distime,lowtime,bridges);
        return bridges;

    }
};