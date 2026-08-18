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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disjoint ds(n);
        unordered_map<string,int> mp;
            for(int i = 0 ; i<n ; i++){
                for(int j = 1; j<accounts[i].size() ; j++){
                 if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]]=i;
                 }
                    else{
                    ds.unionbysize(i,mp[accounts[i][j]]);
                    }
                    }
                     }
                    unordered_map<int,vector<string>> merged;
                     for(auto it : mp){
                       int parent= ds.findpar(it.second);
                       merged[parent].push_back(it.first);
                     }
 
vector<vector<string>> ans;
 for(auto it : merged){
     vector<string> group;
     group.push_back(accounts[it.first][0]);
     sort(it.second.begin(),it.second.end());
     for(auto v : it.second){
        group.push_back(v);
     }
ans.push_back(group);

 }
 
 
return ans;

        
    }
};