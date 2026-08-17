class disjoint{
    vector<int> parent,size;
    public:
    disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0 ; i<n ; i++) parent[i]=i;
          }
    int findpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findpar(parent[node]);
    }
    void unionbysize(int u, int v){
        int up_u= findpar(u);
        int up_v= findpar(v);
        if(up_u==up_v) return;
        if(size[up_u]<size[up_v]){
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else{
             parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
    }
        

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        disjoint ds(n);
        for(int i =0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
        if(stones[i][0]==stones[j][0]|| stones[i][1]==stones[j][1]){
            ds.unionbysize(i,j);

            }
         }
 }
            int stone=0;
            for(int i = 0 ;  i<n ; i++){
                if(ds.findpar(i)==i) stone++;
            }
int ans = n-stone;
return ans;
        
    }
};