class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int x){
    if(parent[x]==x){
        return x;
    }

    return parent[x]=find(parent[x]);
}
void Union(int x,int y){
    int parent_x=find(x);
    int parent_y=find(y);

    if(parent_x==parent_y){
        return ;
    }
    if(rank[parent_x]<rank[parent_y]){
        parent[parent_x]=parent_y;
    }
    else if(rank[parent_x]>rank[parent_y]){
        parent[parent_y]=parent_x;
    }
    else{
        parent[parent_y]=parent_x;
        rank[parent_x]++;
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n,0);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<stones.size();i++){
            for(int j=0;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1]==stones[j][1]){
                    Union(i,j);
                }
            }
        }
        int groups=0;

        for(int i=0;i<n;i++){
            if(parent[i]==i){
                groups++;
            }
        }
        return n-groups;
    }
};