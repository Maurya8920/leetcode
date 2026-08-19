class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
       int n = nums1.size();
       int m = nums2.size();
       for(int i = 0 ; i<n && i<k ; i++){
        pq.push({nums1[i]+nums2[0],{i,0}});
       }
       
       vector<vector<int>> result;
    
       while(k-- && !pq.empty()){
        auto temp= pq.top();
        pq.pop();
        int i = temp.second.first;
        int j= temp.second.second;
        result.push_back({nums1[i],nums2[j]});;
        if(j+1<m){
            pq.push({nums1[i]+nums2[j+1],{i,j+1}});
           
        }
       }
       
        
       return result; 

    }
};