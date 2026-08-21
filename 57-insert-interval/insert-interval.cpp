class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n= intervals.size();
        vector<vector<int>> ans;
      bool vis =false;
      bool merged=false;
      int mergeindex=-1;
        for(int i = 0 ; i<n ; i++){
            if(intervals[i][1]>=newInterval[0] && intervals[i][0]<=newInterval[1]){
             int mergedstart = min(intervals[i][0],newInterval[0]);
              int mergedend = max(intervals[i][1],newInterval[1]);
              
              if(merged==false){
              ans.push_back({mergedstart, mergedend});
               merged=true;
                mergeindex= ans.size()-1;
              }
             
             ans[mergeindex][0]=mergedstart;
              ans[mergeindex][1]=mergedend;
              newInterval[0]=mergedstart;
              newInterval[1]=mergedend;
              vis=true;
             
             }
              else if(intervals[i][0]>newInterval[1]){
                if(vis==false){
                  ans.push_back(newInterval);
                  vis=true;
                }
                   ans.push_back(intervals[i]);
              }
             
             else{
              ans.push_back(intervals[i]);
           
               }
                 }
        if(vis==false){
        ans.push_back(newInterval);
        }
        return ans;
    }
};