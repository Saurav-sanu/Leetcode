class Solution {
public:
vector<int>rankA;
vector<int>parent;

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
        return;
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

    bool equationsPossible(vector<string>& equations) {
        rankA.resize(26,0);
        parent.resize(26);

        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(auto &s:equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
        }
        for(auto &s:equations){
            if(s[1]=='!'){
                int first_parent=find(s[0]-'a');
                int second_parent=find(s[3]-'a');

                if(first_parent==second_parent){
                    return false;
                }
            }
            
        }
        return true;
    }
};
