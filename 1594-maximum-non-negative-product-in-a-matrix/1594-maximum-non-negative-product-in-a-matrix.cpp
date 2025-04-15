class Solution {
public:
typedef long long ll;
int m,n;
int mod=1e9+7;
// vector<vector<pair<ll,ll>>>t;

// pair<ll,ll>solve(int i,int j,vector<vector<int>>& grid){
//     //base case
//     if(i==m-1 && j==n-1){
//         return {grid[i][j],grid[i][j]};
//     }
//     if(t[i][j]!=make_pair(LLONG_MIN,LLONG_MAX)){
//         return t[i][j];
//     }

//     ll maxVal=LLONG_MIN;
//     ll minVal=LLONG_MAX;

//     if(j+1<n){
//         auto[rightMAX,rightMin]=solve(i,j+1,grid);
//         maxVal=max({maxVal,grid[i][j]*rightMAX,grid[i][j]*rightMin});
//         minVal=min({minVal,grid[i][j]*rightMAX,grid[i][j]*rightMin});
//     }
//     if(i+1<m){
//         auto[downMax,downMin]=solve(i+1,j,grid);
//         maxVal=max({maxVal,grid[i][j]*downMax,grid[i][j]*downMin});
//         minVal=min({minVal,grid[i][j]*downMax,grid[i][j]*downMin});
//     }

//     return t[i][j]={maxVal,minVal};
// }

    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        // t = vector<vector<pair<ll, ll>>>(m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        // auto[maxval,minval]=solve(0,0,grid);

        // return maxval<0?-1:maxval%mod;
        vector<vector<pair<ll,ll>>>t(m,vector<pair<ll,ll>>(n));
        t[0][0]={grid[0][0],grid[0][0]};

        for(int j=1;j<n;j++){
            t[0][j].first=t[0][j-1].first* grid[0][j];
            t[0][j].second=t[0][j-1].second* grid[0][j];
        }
        for(int i=1;i<m;i++){
            t[i][0].first=t[i-1][0].first* grid[i][0];
            t[i][0].second=t[i-1][0].second* grid[i][0];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ll upmax=t[i-1][j].first;
                ll upmin=t[i-1][j].second;

                ll leftmax=t[i][j-1].first;
                ll leftmin=t[i][j-1].second;

                t[i][j].first=max({upmax*grid[i][j],upmin*grid[i][j],leftmax*grid[i][j],leftmin*grid[i][j]});
                t[i][j].second=min({upmax*grid[i][j],upmin*grid[i][j],leftmax*grid[i][j],leftmin*grid[i][j]});
            }
        }
        auto [maxval,minval]=t[m-1][n-1];

        return maxval<0?-1:maxval%mod;

    }
};