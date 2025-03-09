class Solution {
public:
typedef pair<int,int>P;
int prims(vector<vector<P>>&adj,int V){
    vector<bool>inMst(V,false);

    priority_queue<P,vector<P>,greater<P>>pq;

    pq.push({0,0});
    int sum=0;


    while(!pq.empty()){
        auto element=pq.top();
        pq.pop();

        int dist=element.first;
        int node=element.second;

        if(inMst[node]==true){
            continue;
        }

        inMst[node]=true;
        sum+=dist;

        for(auto &ngr:adj[node]){
            int ngr_node=ngr.first;
            int ngr_dist=ngr.second;

            if(!inMst[ngr_node]){
                pq.push({ngr_dist,ngr_node});
            }
        }
    }
    return sum;

}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<P>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt=abs(points[j][1]-points[i][1])+abs(points[j][0]-points[i][0]);

                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }

        return prims(adj,n);
    }
};