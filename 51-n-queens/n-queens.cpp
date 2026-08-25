class Solution {
public:
bool issafe(vector<string> & board , int row , int col , int n){
    for(int j =0 ; j<n ; j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
     for(int i =0 ; i<n ; i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    // left diagonal
    for(int i=row , j=col; i>=0 && j>=0;){
        if(board[i][j]=='Q') return false;
        i-- ;
         j--;
    }
    // right diagonal 
    for(int i=row , j=col;    i>=0 && j<n;  ){
        if(board[i][j]=='Q') return false;
        i-- ;
         j++;
    }
    return true;
    
}
void nqueen(vector<string>& board,vector<vector<string>> & ans, int n ,int row){
    if(n==row){
        ans.push_back(board);
        return;
    }
    for(int j= 0 ; j<n ; j++){
        if(issafe(board,row,j,n)){
            board[row][j]='Q';
        
            nqueen(board ,ans, n,row+1);
            board[row][j]='.';
        }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        nqueen(board , ans , n ,0);
        
return ans;

    }
};