class Solution {
public:
bool issafe(vector<vector<char>> & board,int r, int c,int k){
    // check row
    for(int j= 0 ; j<9 ; j++){
        if(board[r][j]=='0'+k) return false;
    }
    // check col
    for(int i= 0 ; i<9 ; i++){
        if(board[i][c]=='0'+k) return false;
    }
    // check 3X3 grid
    int startrow=(r/3)*3;
    int startcol=(c/3)*3;

    for(int i= startrow ; i<startrow+3; i++){
        for(int j=startcol ; j<startcol+3 ; j++){
  if(board[i][j]=='0'+k) return false;
        }
        }
        return true;

}
bool solve(vector<vector<char>> & board , int r , int c){
    // all row filled return true
if(r==9){
    return true;
    
} 
// already filled current cell
   if(board[r][c]!='.' ){
           if(c==8){
            if(solve(board,r+1,0)) return true;
           }
           else{
            if(solve(board,r,c+1)) return true;
           }
              }
              // fill cell try 1 to 9 digits
for(int k =1 ; k<=9 ; k++){
        if(board[r][c]=='.' && issafe(board , r,c,k)){
            // place numbers
            board[r][c]='0'+k;
        
            if(c==8){
                // if suduko not solved then backtack
               if (solve(board, r+1,0)==false){
                   board[r][c]='.';
               }
               else{
                // sudko solved
                return true;
               }
            }
            if(c!=8){
                 // if suduko not solved then backtack
                if(solve(board, r,c+1)==false){
                  board[r][c]='.';
                }
                else{
                    // sudoko solved
                    return true;
                }
            }
        }

    }
    
   
return false;
}

    void solveSudoku(vector<vector<char>>& board) {
        // call with 0,0 intially
        solve(board,0,0);
      
     
    }
};