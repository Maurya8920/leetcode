class Solution {
public:

bool dfs(int src  ,vector<vector<int>>& graph ,vector<int>& color){
   for(auto v : graph[src]){
        if(color[v]==-1){
             color[v]=1-color[src];
            if(!dfs(v,graph,color)){ 
                return false;
            }
        }
         else{
              if(color[v]==color[src]) return false;
             }
        } 
    
 return true;
   
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0 ; i<n ; i++){
                if(color[i]==-1){
                color[i]=0;
                
     if(!dfs(i,graph,color)) return false; 
        }
            }
         return true;
    }
};