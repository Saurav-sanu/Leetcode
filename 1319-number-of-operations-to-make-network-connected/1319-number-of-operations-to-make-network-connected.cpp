class Solution {
public:
vector<int>parent;
vector<int>rankA;

int find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x]);
}
void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);

    if(x_parent==y_parent){
        return ;
    }
    if(rankA[x_parent]<rankA[y_parent]){
        parent[x_parent]=y_parent;
    }
    else if(rankA[y_parent]<rankA[x_parent]){
        parent[y_parent]=x_parent;
    }
    else{
        parent[y_parent]=x_parent;
        rankA[x_parent]+=1;

    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rankA.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        if(connections.size()<n-1){
            return -1;
        }
        int component=n;

        for(auto &vec:connections){
            if(find(vec[0])!=find(vec[1])){
                Union(vec[0],vec[1]);
                component--;
            }
        }
        return component-1;



    }
};