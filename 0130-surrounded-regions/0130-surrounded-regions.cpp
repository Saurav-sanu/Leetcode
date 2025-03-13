class Solution {
public:
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};

void DFS(int i,int j,vector<vector<int>>&visited,vector<vector<char>>&board,int n,int m){
    //
    visited[i][j]=true;

    for(auto dir:directions){
        int new_i=dir[0]+i;
        int new_j=dir[1]+j;

        if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && visited[new_i][new_j]==0 && board[new_i][new_j]=='O'){
            DFS(new_i,new_j,visited,board,n,m);
        }
    }
}

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        //for(last and first row)
        for(int j=0;j<m;j++){
            //first row
            if(board[0][j]=='O' && visited[0][j]==0){
                DFS(0,j,visited,board,n,m);
            }
            //last row
            if(board[n-1][j]=='O' && visited[n-1][j]==0){
                DFS(n-1,j,visited,board,n,m);
            }
        }
        for(int i=0;i<n;i++){
            //first col
            if(board[i][0]=='O' && visited[i][0]==0){
                DFS(i,0,visited,board,n,m);
            }
            //last col
            if(board[i][m-1]=='O' && visited[i][m-1]==0){
                DFS(i,m-1,visited,board,n,m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        


        
    }
};