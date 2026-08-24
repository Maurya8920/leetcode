class Solution {
public:
set<vector<int>> s;
void comb(vector<int>& candidates,int idx , int target,vector<int> & ans , vector<vector<int>>& result){
    int n = candidates.size();
    if(target<0) return ;
    if(target==0){
        result.push_back(ans);
        return;
    }

    for(int i =idx ; i<n ; i++){
        if(i>idx && candidates[i-1]==candidates[i]){
            continue;
        }
    ans.push_back(candidates[i]);
    comb(candidates,i+1,target-candidates[i],ans,result);
    ans.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        comb(candidates,0,target,ans,result);
        return result;
        
    }
};