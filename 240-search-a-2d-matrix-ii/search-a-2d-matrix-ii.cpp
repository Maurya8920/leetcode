class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =matrix.size();
        int m= matrix[0].size();
        int rowindex = n-1; int colindex = 0;
        
        while(rowindex>=0 && colindex<m){
            if(matrix[rowindex][colindex]==target){
                return true;
            }
            else if(matrix[rowindex][colindex]<target){
                colindex++;
            }
            else{
                rowindex--;
            }
        }

       return false; 
    }
};