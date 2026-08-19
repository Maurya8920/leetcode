class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        string ans="";
        for(char c : s){
            mp[c]++;

        }
        for(auto it : mp ){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            for(int i = 0 ; i<pq.top().first; i++){
                ans.push_back(pq.top().second);
               

            }
             pq.pop();
            
        }
return ans;
    }
};