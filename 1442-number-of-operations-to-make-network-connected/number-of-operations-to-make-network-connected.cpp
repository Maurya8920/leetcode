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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m<n-1) return -1;
        disjoint ds(n);
        int count=0;
       for(auto it : connections){
        int u = it[0];
        int v = it[1];
        if(ds.findpar(u)==ds.findpar(v)){
            count++;
             }
        else{
            ds.unionbysize(u,v);
            }
       }
       int component=0;
       for(int i = 0 ; i<n ; i++){
        if(ds.findpar(i)==i){
        component++;
        }
}         
if(count>=component-1){
    return component-1;
}
    return -1;    
    }
};