class Solution {
public:
//bfs

void bfs(int src,vector<vector<int>>& isConnected , vector<bool> & vis){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    while(!q.empty()){
        int city = q.front();
        q.pop();
      for(int v = 0 ; v<isConnected.size(); v++){
        if(isConnected[city][v]==1 && !vis[v]){
            vis[v]=true;
            q.push(v);
        }
    }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int province=0;
        int n = isConnected.size();
        vector<bool> vis(n,false);
        for(int v= 0 ; v<n ; v++){
            if(!vis[v]){
                province++;
             bfs(v,isConnected,vis);
            }
        }
        return province;
    }
};