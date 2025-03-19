class Solution {
public:

//using dikstra 
typedef pair<int,int>P;
void dikstra(unordered_map<int,vector<pair<int,int>>>&adj,int source,vector<int>&result){
    priority_queue<P,vector<P>,greater<P>>q;
    q.push({0,source});
    fill(result.begin(),result.end(),INT_MAX);
    result[source]=0;

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


//using bellmon ford
class Solution {
public:

//using bellmonford
typedef pair<int,int>P;
void bellmon(int n,vector<vector<int>>& edges,int source,vector<int>&result){
    fill(result.begin(),result.end(),INT_MAX);
    result[source]=0;

    for(int count=1;count<n;count++){
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            if(result[u]!=INT_MAX && result[u]+wt<result[v]){
                result[v]=result[u]+wt;
            }
            if(result[v]!=INT_MAX && result[v]+wt<result[u]){
                result[u]=result[v]+wt;
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

            VECTOR[u][v]=wt;
            VECTOR[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            VECTOR[i][i]=0;
        }

        for(int i=0;i<n;i++){
            bellmon(n,edges,i,VECTOR[i]);
        }
        return shortestNeighbour(n,VECTOR,distanceThreshold);

    }
};


//floys warshalll
class Solution {
public:

//using floyswarshall
typedef pair<int,int>P;
void floydwarshall(int n,vector<vector<int>>&VECTOR){
    for(int via=0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                VECTOR[i][j]=min(VECTOR[i][j],VECTOR[i][via]+VECTOR[via][j]);
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
        vector<vector<int>>VECTOR(n,vector<int>(n,1e9+7));
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];

            VECTOR[u][v]=wt;
            VECTOR[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            VECTOR[i][i]=0;
        }

        
        floydwarshall(n,VECTOR);
        
        return shortestNeighbour(n,VECTOR,distanceThreshold);

    }
};
