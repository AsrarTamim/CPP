
class Solution {
public:
    int delrow[4] = {+1 , 0 , -1 , 0};
    int delcol[4] = {0 , +1 , 0 , -1};
    bool solve(vector<vector<char>>& board , vector<vector<bool>> &vis , string word ,int row , int col , int n , int m , int idx){

        int s = word.size();
        if(idx == s-1 ){
            return true;
        }
        for(int i=0 ; i<4 ; i++){
            int r = row + delrow[i];
            int c = col + delcol[i];
            if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && (word[idx+1] == board[r][c])){
                vis[r][c] = true;
                if(solve(board  , vis , word , r , c,n , m , idx+1)){
                    return true;                    
                }
                else{
                    vis[r][c]  = false;
                }
            }
        }
        return false;    
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n =board.size();
        int m = board[0].size();
        if(word.size() > n*m){
            return false;
        }
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        int idx=0;
        for(int row=0 ; row<n ; row++){
            for(int col=0 ; col<m ; col++){
                vis[row][col]=true;
                if((word[idx] == board[row][col]) && solve(board , vis , word , row , col , n , m , idx)){
                    return true;
                }
                vis[row][col] = false;
            }
        }
        return false;
    }
};