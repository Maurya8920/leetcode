class Solution {
public:
bool dfs(int src,vector<vector<int>>& adj,vector<bool> &vis,vector<bool> &pathvis){
    vis[src]=true;
    pathvis[src]=true;
    for(auto v : adj[src]){
        if(!vis[v]){
            if(dfs(v,adj,vis,pathvis)) return true;
        }
        else{
            if(pathvis[v]) return true;
        }
    }
    pathvis[src]=false;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> pathvis(numCourses,false);
        vector<vector<int>> adj( numCourses);
        for(auto edge :prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
        }
        for(int i = 0 ; i<numCourses ; i++ ){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)) return false;
            }
        }
        return true;
    }
};