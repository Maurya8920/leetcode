class Solution {
public:
static bool cmp(vector<int> & a , vector<int> &b){
    return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n= intervals.size();
        int i =1;
        int cnt =0;
        sort(intervals.begin(),intervals.end(),cmp);
        int prev =0;
        while(i<n){
            if(intervals[prev][1]>intervals[i][0]){
                cnt++;
            }else{
                prev=i;
            }
           
          i++; 
        }
return cnt;
        
    }
};