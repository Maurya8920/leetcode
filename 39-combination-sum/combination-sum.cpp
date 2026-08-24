class Solution {
public:
set<vector<int>> s;
void combsum(vector<int> & candidates , int target,int i , vector<int> & ans , vector<vector<int>> & result){
    int n = candidates.size();
    if(i==n  || target<0){
        return;
    }
    if(target==0){
        if(s.find(ans)==s.end()){
        result.push_back(ans);
        s.insert(ans);
        
        }
         return;
    }
   ans.push_back(candidates[i]);
// single exclusion
     combsum(candidates,target-candidates[i],i+1,ans,result);
     // multiple exclusion
    combsum(candidates,target-candidates[i],i,ans,result);
    ans.pop_back();  // backtrack
   combsum(candidates,target,i+1,ans,result);
    
    
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> result;
        combsum(candidates,target,0,ans,result);
        return result;


        
    }
};