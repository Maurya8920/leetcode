class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n= intervals.size();
        int i= 0;
        vector<vector<int>> result;
        // left part
        while(i<n && intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
            i=i+1;
        }
        // overlap
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
          i=  i+1;

        }
        result.push_back(newInterval);
        // right part
        while(i<n){
            result.push_back(intervals[i]);
            i=i+1;
        }
        return result;
    }
};