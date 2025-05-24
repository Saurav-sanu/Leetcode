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

        board[row][col]='Q';
        cols.insert(col);
        diagonals.insert(diagonalconst);
        antidiagonals.insert(antidiagonalconst);



        solve(n,board,ans,row+1);

        board[row][col]='.';
        cols.erase(col);
        diagonals.erase(diagonalconst);
        antidiagonals.erase(antidiagonalconst);

    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));

        vector<vector<string>>ans;
 
        solve(n,board,ans,0);

        return ans;
    }
};