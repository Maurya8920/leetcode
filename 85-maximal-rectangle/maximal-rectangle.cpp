class Solution {
public:
vector<int> nextsmallelement(vector<int>& arr , int n){
    
    vector<int> ans(n);
    stack<int> st;
    for(int i =n-1 ; i>=0 ; i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> prevsmallelement(vector<int> &arr , int n){
    
    vector<int> ans(n);
    stack<int> st;
    for(int i =0 ; i<n ; i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}

 int largestRectangleArea(vector<int>& heights, int n) {

      
        vector<int> next(n);
        next = nextsmallelement(heights, n);
        vector<int> prev(n);
        prev = prevsmallelement(heights, n);
        int newarea=0;
        for(int i = 0 ; i<n ; i++){
            int l= heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b= next[i]-prev[i]-1;
            int area = l*b;
            newarea = max(area , newarea);


        }

        
       return newarea; 
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
    int m= matrix[0].size();
    vector<int> heights(m,0);
    int area =0;
    // int area = largestRectangleArea(heights, m);
    for(int i = 0; i<n ; i++){
        for(int j =0 ; j<m ; j++){
            if(matrix[i][j]!='0') {
                heights[j]+=1;

        }
        else{
            heights[j]=0;
        }
           
        }
         area=max(area ,largestRectangleArea(heights,m) );
        
 }
    
     return area;  

        
    }
};