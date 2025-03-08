class Solution {
public:
vector<vector<int>>direction={{0,1},{1,0},{-1,0},{0,-1}};
typedef pair<int,pair<int,int>>P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        auto isSafe=[&](int a,int b){
            return (a>=0 && a<m && b>=0 && b<n);
        };

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>q;
        result[0][0]=0;
        q.push({0,{0,0}});

        while(!q.empty()){
            int diff=q.top().first;
            auto &front=q.top().second;
            int x=front.first;
            int y=front.second;
            q.pop();

            for(auto &dir:direction){
                int newx=x+dir[0];
                int newy=y+dir[1];

                if(isSafe(newx,newy)){
                    int absdiff=abs(heights[x][y]-heights[newx][newy]);
                    int maxx=max(diff,absdiff);
                    if(result[newx][newy]>maxx){
                        result[newx][newy]=maxx;
                        q.push({maxx,{newx,newy}});
                    }
                }
            }

        }
        return result[m-1][n-1];
    }
};