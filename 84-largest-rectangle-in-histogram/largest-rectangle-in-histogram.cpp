class Solution {
public:
vector<int> nextsmallelement(vector<int> arr , int n){
    
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
vector<int> prevsmallelement(vector<int> arr , int n){
    
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

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        next = nextsmallelement(heights, n);
        vector<int> prev(n);
        prev = prevsmallelement(heights, n);
        int newarea=INT_MIN;
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
};