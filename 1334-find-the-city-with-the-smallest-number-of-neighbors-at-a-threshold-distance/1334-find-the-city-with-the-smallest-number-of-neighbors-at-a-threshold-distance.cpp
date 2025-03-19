class Solution {
public:

//using dikstra 
typedef pair<int,int>P;
void dikstra(unordered_map<int,vector<pair<int,int>>>&adj,int source,vector<int>&result){
    priority_queue<P,vector<P>,greater<P>>q;
    q.push({0,source});
    result[source]=0;
    fill(result.begin(),result.end(),INT_MAX);

    while(!q.empty()){
        auto top_el=q.top();
        q.pop();

        int dist=top_el.first;
        int nd=top_el.second;

        for(auto vec:adj[nd]){
            int wt=vec.second;
            int node=vec.first;

            if(dist+wt<result[node]){
                result[node]=dist+wt;
                q.push({result[node],node});
            }
        }

    }


}
int shortestNeighbour(int n,vector<vector<int>>&VECTOR,int distanceThreshold){
    int city=-1;
    int leastReachable=INT_MAX;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(i!=j && VECTOR[i][j]<=distanceThreshold){
                count++;
            }
        }
        if(count<=leastReachable){
            leastReachable=count;
            city=i;
        }
    }
    return city;
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>VECTOR(n,vector<int>(n,INT_MAX));
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        for(int i=0;i<n;i++){
            VECTOR[i][i]=0;
        }

        for(int i=0;i<n;i++){
            dikstra(adj,i,VECTOR[i]);
        }
        return shortestNeighbour(n,VECTOR,distanceThreshold);

    }
};