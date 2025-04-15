class Solution {
public:
int t[101][101];
vector<vector<int>>direction={{1,0},{0,1}};
int solve(int i,int j,int m,int n){
    auto isSafe=[&](int a,int b){
        return(a>=0 && a<m && b>=0&& b<n);
    };

    if(i==m-1 && j==n-1){
        return 1;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int result=0;

    for(auto dir:direction){
        int new_i=i+dir[0];
        int new_j=j+dir[1];


        if(isSafe(new_i,new_j)){
            result+=solve(new_i,new_j,m,n);
        }
    }
    return t[i][j]=result;
}
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));

        return solve(0,0,m,n);
    }
};