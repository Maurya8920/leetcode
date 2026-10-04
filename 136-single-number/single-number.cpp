class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =-1;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0 ; i<n ; i++){
            mp[nums[i]]++;

        }
    for(auto it :mp){
        if(it.second==1){
            ans=it.first;
        }
    }
        // or
        // for(int i=0 ; i<n ; i++){
        //     if(mp[nums[i]]==1){
        //         ans= nums[i];

        //     }
        // }
        return ans;
    }
};