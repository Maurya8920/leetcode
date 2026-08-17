class disjointset {
    
    public:
    vector<int> rank,parent,size;
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i =0 ; i<=n ; i++ ) {
            parent[i]=i;
            
        }
    }
    int findpar(int node){
        if(node==parent[node]) return node;
        return parent[node]= findpar(parent[node]);
    }
    void unionbyrank(int u , int v){
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            // same
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;

        }
    }
      void unionbysize(int u , int v){
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
              parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }


};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
        disjointset ds(n);

    
        for(int i = 0 ; i<n ; i++){
            for(int j= 0; j<n ; j++){
                if(isConnected[i][j]==1){
                    ds.unionbyrank(i,j);

                }
            }
        }
        int count=0;
        for(int i = 0 ; i<n ; i++){
            if(ds.parent[i]==i) count++;
        }
        return count;

        
    }
};