class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        for(int i = 0 ; i<arr.size() ; i++){
            int e = arr[i];
            mp[e]++;
        }
              for(auto it : mp){
            if(it.first==it.second){
            maxi=max(maxi ,it.first);
        
            }
           
            
        }

        if(maxi==INT_MIN){
            return -1;
        }
        
      
        return maxi;
    }
};