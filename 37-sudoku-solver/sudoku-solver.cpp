class Solution {
public:
bool issafe(vector<vector<char>> & board,int r, int c,int k){
    for(int j= 0 ; j<9 ; j++){
        if(board[r][j]=='0'+k) return false;
    }
    for(int i= 0 ; i<9 ; i++){
        if(board[i][c]=='0'+k) return false;
    }
    int n=(r/3)*3;
    int m=(c/3)*3;

    for(int y= n ; y<n+3; y++){
        for(int u=m ; u<m+3 ; u++){
  if(board[y][u]=='0'+k) return false;
        }
        }
        return true;

}
bool solve(vector<vector<char>> & board , int r , int c){
if(r==9){
    return true;
    
} 
   if(board[r][c]!='.' ){
           if(c==8){
            if(solve(board,r+1,0)) return true;
           }
           else{
            if(solve(board,r,c+1)) return true;
           }
              }
for(int k =1 ; k<=9 ; k++){
        if(board[r][c]=='.' && issafe(board , r,c,k)){
            board[r][c]='0'+k;
        
            if(c==8){
               if (solve(board, r+1,0)==false){
                   board[r][c]='.';
               }
               else{
                return true;
               }
            }
            if(c!=8){
                if(solve(board, r,c+1)==false){
                  board[r][c]='.';
                }
                else{
                    return true;
                }
            }
        }

    }
   
return false;
}

    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
      
     
    }
};