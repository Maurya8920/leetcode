class Solution {
public:
void sub(vector<int> & nums , int i  ,vector<int> & ans , vector<vector<int>> & result){
    int n = nums.size();
    if(i==n){
        result.push_back(ans);
        return;
    }
   
    ans.push_back(nums[i]);
    
    sub(nums, i+1,ans , result);
    ans.pop_back();
    int idx = i+1;
    while(idx<n &&  nums[idx-1]==nums[idx] ){
        idx++; //skip duplicates
    }
    sub(nums,idx, ans,result);
    
    
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        sub(nums,0,ans,result);
        return result;

        
    }
};