class Solution {
public:
int N,M,K;
int MOD=1e9+7;
int solve(int index,int search_cost,int maxCost,vector<vector<vector<int>>>&t){
    //base case
    if(index==N){
        if(search_cost==K){
            return 1;
        }
        return 0;
    }

    if(t[index][search_cost][maxCost]!=-1){
        return t[index][search_cost][maxCost];
    }

    int result=0;
    for(int i=1;i<=M;i++){
        if(i>maxCost){
            result=(result+solve(index+1,search_cost+1,i,t))%MOD;
        }
        else{
            result=(result+solve(index+1,search_cost,maxCost,t))%MOD;
        }
    }
    return t[index][search_cost][maxCost]=result%MOD;
}
    int numOfArrays(int n, int m, int k) {
        N=n;
        M =m;
        K=k;
        vector<vector<vector<int>>>t(n+1,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        return solve(0,0,0,t);
    }
};