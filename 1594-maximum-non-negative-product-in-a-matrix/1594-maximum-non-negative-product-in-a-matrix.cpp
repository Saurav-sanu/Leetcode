class Solution {
public:
typedef long long ll;
int m,n;
int mod=1e9+7;
vector<vector<pair<ll,ll>>>t;

pair<ll,ll>solve(int i,int j,vector<vector<int>>& grid){
    //base case
    if(i==m-1 && j==n-1){
        return {grid[i][j],grid[i][j]};
    }
    if(t[i][j]!=make_pair(LLONG_MIN,LLONG_MAX)){
        return t[i][j];
    }

    ll maxVal=LLONG_MIN;
    ll minVal=LLONG_MAX;

    if(j+1<n){
        auto[rightMAX,rightMin]=solve(i,j+1,grid);
        maxVal=max({maxVal,grid[i][j]*rightMAX,grid[i][j]*rightMin});
        minVal=min({minVal,grid[i][j]*rightMAX,grid[i][j]*rightMin});
    }
    if(i+1<m){
        auto[downMax,downMin]=solve(i+1,j,grid);
        maxVal=max({maxVal,grid[i][j]*downMax,grid[i][j]*downMin});
        minVal=min({minVal,grid[i][j]*downMax,grid[i][j]*downMin});
    }

    return t[i][j]={maxVal,minVal};
}

    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        t = vector<vector<pair<ll, ll>>>(m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        auto[maxval,minval]=solve(0,0,grid);

        return maxval<0?-1:maxval%mod;
    }
};