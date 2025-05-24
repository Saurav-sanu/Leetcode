// appproach 1
class Solution {
public:

bool isvalid(int n,vector<string>&board,int row,int col){
    //
    for(int i=row-1;i>=0;i--){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void solve(int n,vector<string>&board,vector<vector<string>>&ans,int row,int col){
    //base cses
    if(row==n){
        ans.push_back(board);
        return;
    }

    for(int col=0;col<n;col++){
        if(isvalid(n,board,row,col)){
            board[row][col]='Q';
            solve(n,board,ans,row+1,col);
            board[row][col]='.';
           
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));

        vector<vector<string>>ans;

        solve(n,board,ans,0,0);

        return ans;
    }
};



class Solution {
public:
//appraoch 2
unordered_set<int>cols;
unordered_set<int>diagonals;
unordered_set<int>antidiagonals;

void solve(int n,vector<string>&board,vector<vector<string>>&ans,int row){
    //base cses
    if(row==n){
        ans.push_back(board);
        return;
    }

    for(int col=0;col<n;col++){
        int diagonalconst=row+col;
        int antidiagonalconst=row-col;

        if(cols.find(col)!=cols.end() || diagonals.find(diagonalconst)!=diagonals.end() || antidiagonals.find(antidiagonalconst)!=antidiagonals.end()){
            continue;
        }

        cols.insert(col);
        diagonals.insert(diagonalconst);
        antidiagonals.insert(antidiagonalconst);
        board[row][col]='Q';



        solve(n,board,ans,row+1);

        cols.erase(col);
        diagonals.erase(diagonalconst);
        antidiagonals.erase(antidiagonalconst);
        board[row][col]='.';

    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));

        vector<vector<string>>ans;
 
        solve(n,board,ans,0);

        return ans;
    }
};
