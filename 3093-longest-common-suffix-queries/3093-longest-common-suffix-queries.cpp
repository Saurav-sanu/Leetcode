class Solution {
public:
struct trieNode{
    int idx;
    trieNode* children[26];

    ~trieNode(){
        for( int i=0;i<26;i++){
            delete children[i];
        }
    }
};


trieNode* getNode(int i){
    trieNode* newNode=new trieNode();
    newNode->idx=i;
    for(int j=0;j<26;j++){
        newNode->children[j]=NULL;
       
    }
    return newNode;
}



    void insert(trieNode* root,int i,vector<string>& wordsContainer){
        string word=wordsContainer[i];
        int n=word.size();
        for(int j=n-1;j>=0;j--){
            int idx=word[j]-'a';
            if(root->children[idx]==NULL){
                root->children[idx]=getNode(i);
            }
            root=root->children[idx];

            if(wordsContainer[root->idx].length()>n){
                root->idx=i;
            }

        }

    }

    int searchTrie(trieNode* root,string & word){
        int result_idx=root->idx;
        int n=word.length();
        for(int i=n-1;i>=0;i--){
            int ind=word[i]-'a';
            root=root->children[ind];
            if(root==NULL){
                return result_idx;
            }
            result_idx=root->idx;
        }

        return result_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m=wordsContainer.size();
        int n=wordsQuery.size();
        vector<int>result(n);

        trieNode* root=getNode(0);

        for(int i=0;i<m;i++){
            int idx=root->idx;
            if(wordsContainer[idx].length()>wordsContainer[i].length()){
                root->idx=i;
            }
            insert(root,i,wordsContainer);
        }

        for(int i=0;i<n;i++){
            result[i]=searchTrie(root,wordsQuery[i]);
        }

        delete root;
        return result;

    }
};