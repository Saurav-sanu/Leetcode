class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x]);
}
void Union(int x ,int y){
    //base case
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent){
        return;
    }

    if(rank[x_parent]>rank[y_parent]){
        parent[y_parent]=x_parent;
       
    }
    else if(rank[y_parent]>rank[x_parent]){
        parent[x_parent]=y_parent;
    }
    else{
        parent[x_parent]=y_parent;
        rank[y_parent]++;

    }

}
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        parent.resize(26);
        rank.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=1;
        }

        for(string &s:equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
        }
        for(string &s:equations){
            if(s[1]=='!'){
                int x_parent=find(s[0]-'a');
                int y_parent=find(s[3]-'a');

                if(x_parent==y_parent){
                    return false;
                    
                }
            }

        }
        
        return true;
    }
};