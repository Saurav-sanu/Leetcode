class Solution {
public:
    bool valid(int sr,int er,int sc,int ec,vector<vector<char>>& board){
        unordered_set<char>st;
        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(st.find(board[i][j])!=st.end()){
                    return false;
                }

                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        //validate row;
        for(int row=0;row<m;row++){
            unordered_set<char>st;
            for(int col=0;col<n;col++){
                if(board[row][col]=='.'){
                    continue;
                }

                if(st.find(board[row][col])!=st.end()){
                    return false;
                }

                st.insert(board[row][col]);
            }
        } 
        //validate col
        for(int col=0;col<n;col++){
            unordered_set<char>st;
            for(int row=0;row<m;row++){
                if(board[row][col]=='.'){
                    continue;
                }

                if(st.find(board[row][col])!=st.end()){
                    return false;
                }

                st.insert(board[row][col]);
            }
        } 

        for(int sr=0;sr<9;sr+=3){
            int endr=sr+2;
            for(int sc=0;sc<9;sc+=3){
                int endc=sc+2;
                if(!valid(sr,endr,sc,endc,board)){
                    return false;
                }
            }
        }

        return true;
        
    }

};