class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i = 0 ; i<arr.size() ; i++){
            int distance=abs(x-arr[i]);
               pq.push({distance,arr[i]});
        }
         while(pq.size()>k){
            pq.pop();
            }
            while(!pq.empty()){
               ans.push_back(pq.top().second);
               pq.pop(); 
            }
        sort(ans.begin(),ans.end());
        return ans;
    }
};