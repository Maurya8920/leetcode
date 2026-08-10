class Solution {
public:
int count = 0;
bool dfs(int src,vector<bool>&vis, vector<vector<int>>&rooms,int &count){
    vis[src]=true;
    count++;
    if(count==rooms.size()) return true;
    for(int v : rooms[src]){
        if(!vis[v]){
          if (dfs(v,vis,rooms,count)) return true;
        }
    }
    return false;
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n =  rooms.size();
       vector<bool> vis(n ,false);
        return dfs(0,vis,rooms,count);
        
    }
};