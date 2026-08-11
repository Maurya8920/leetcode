class Solution {
public:
int province=0;
void dfs(int src,vector<vector<int>>& isConnected , vector<bool> & vis, int& province){
    if(vis[src]==true) return;
    vis[src]=true;
      for(int v = 0 ; v<isConnected.size(); v++){
        if(isConnected[src][v]==1 && !vis[v]){
            dfs(v,isConnected,vis,province);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);
        for(int v= 0 ; v<n ; v++){
            if(!vis[v]){
                province++;
             dfs(v,isConnected,vis,province);
            }
        }
        return province;
    }
};