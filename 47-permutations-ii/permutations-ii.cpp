class Solution {
public:

void perm(vector<int> & nums, int idx , vector<vector<int>> & result){
    int n = nums.size();
    if(idx==n){
      result.push_back(nums);
      return;  
    }
    set<int> s;
    for(int i =idx ; i<n ; i++){
        if(s.find(nums[i])!=s.end()) continue; // means visited
        s.insert(nums[i]); // mark visited
       
        swap(nums[idx],nums[i]);
        perm(nums,idx+1,result);
        swap(nums[idx],nums[i]);
        
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        perm(nums,0,result);
        return result;
        
        
    }
};