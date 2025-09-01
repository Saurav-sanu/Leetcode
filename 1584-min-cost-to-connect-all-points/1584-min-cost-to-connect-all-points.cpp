class Solution {
public:
typedef pair<int,int>p;

int prims(unordered_map<int,vector<p>>&adj,int V){
    int sum=0;
    priority_queue<p,vector<p>,greater<p>>pq;
    vector<bool>visited(V,false);
    pq.push({0,0});

    while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();
        int node=temp.second;
        int dist=temp.first;

        if(visited[node]){
            continue;
        }
        visited[node]=true;
        sum+=dist;

        for(auto &vec:adj[node]){
            int wt=vec.second;
            int othernode=vec.first;

            if(visited[othernode]==false){
                pq.push({wt,othernode});
            }
        }

    }
    return sum;
    
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<p>>adj;
        
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x_points=abs(points[j][0]-points[i][0]);
                int y_points=abs(points[j][1]-points[i][1]);

                int dist=x_points+y_points;

                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        return prims(adj,n);
    }
};