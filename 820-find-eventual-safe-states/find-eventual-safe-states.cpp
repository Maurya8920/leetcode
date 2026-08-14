class Solution {
public:

        
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revadj(n);
            for(int i = 0 ; i<n ; i++){
            for (auto it : graph[i]){
              revadj[it].push_back(i);
            }
        }
        vector<int> indegree( n,0);
        for(int i =0; i<n ; i++){
            for(auto it : revadj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i<n ;i++ ){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node =  q.front();
            q.pop();
            ans.push_back(node);
            for(auto v : revadj[node]){
                indegree[v]--;
                if(indegree[v]==0) {
                    q.push(v);
                }
            }

        }
    sort(ans.begin(), ans.end());
    return ans;
  }
};