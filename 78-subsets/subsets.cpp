class Solution {
public:
void sub(vector<int> & nums , int i , vector<int> & ans , vector<vector<int>> &result ){
    int n= nums.size();
    if(i==n) {
    result.push_back(ans);
    return;
    }
    // include
    ans.push_back(nums[i]);
     sub(nums,i+1,ans,result);
     // backtrack
    ans.pop_back();
    // exclude
    sub(nums,i+1,ans,result);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
    sub(nums,0,ans,result);
    return result;
        
    }
};