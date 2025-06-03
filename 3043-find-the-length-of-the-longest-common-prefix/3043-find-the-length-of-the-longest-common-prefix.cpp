class Solution {
public:
struct trieNode{
    // char digit;
    trieNode* children[10];

};
trieNode* getNode(){
    trieNode* node=new trieNode();

    for(int i=0;i<10;i++){
        node->children[i]=NULL;
    }
    return node;
}
void insert(trieNode* root,int num){
    trieNode* crawler=root;
    string num_str=to_string(num);
    for(int i=0;i<num_str.length();i++){
        int idx=num_str[i]-'0';
        if(crawler->children[idx]==NULL){
            crawler->children[idx]=getNode();
        }
        crawler=crawler->children[idx];
    }
}
int search(trieNode* root,int num){
    int length=0;
    trieNode* crawler=root;
    string numword=to_string(num);
    for(int i=0;i<numword.size();i++){
        int idx=numword[i]-'0';
        if(crawler->children[idx]){
            length++;
            crawler=crawler->children[idx];
        }
        else{
            break;
        }
    }
    return length;
}
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxi=0;
        trieNode* root=new trieNode();
        for(auto num:arr1){
            insert(root,num);
        }

        for(auto num1:arr2){
            maxi=max(maxi,search(root,num1));
        }
        return maxi;
    }
};