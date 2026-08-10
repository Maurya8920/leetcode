class Solution {
public:
bool dfs(int src , int destination,  vector<bool>&vis,vector<vector<int>>& adj){
    if(src==destination) return true;
    vis[src]=true;
    for(int neighbour :adj[src]){
    if(!vis[neighbour]){
        bool path = dfs(neighbour,destination,vis,adj);
        if(path==true) return true;
    }
    }
return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge :edges){
            int u =  edge[0];
            int v= edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n ,false);
        return dfs(source , destination , vis , adj);

        
    }
};