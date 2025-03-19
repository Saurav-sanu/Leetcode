class Solution {
public:

//using dikstra 
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