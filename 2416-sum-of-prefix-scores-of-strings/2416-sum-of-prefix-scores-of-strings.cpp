class Solution {
public:
struct trieNode{
    int countP=0;
    trieNode* children[26];
};

trieNode* getNode(){
    trieNode* node=new trieNode();
    for(int i=0;i<26;i++){
        node->children[i]=NULL;
    }
    node->countP=0;
    return node;
}

void insert(trieNode* root,string& word){
    trieNode* crawler=root;
    for(int i=-0;i<word.length();i++){
        int idx=word[i]-'a';
        if(crawler->children[idx]==NULL){
            crawler->children[idx]=getNode();

        }
        crawler->children[idx]->countP+=1;
        crawler=crawler->children[idx];
    }
}
int getScore(trieNode* root,string & word){
    int score=0;
    trieNode* crawler=root;
    for(int i=0;i<word.length();i++){
        int idx=word[i]-'a';
        if (!crawler->children[idx]) break; 
        score+=crawler->children[idx]->countP;
        crawler=crawler->children[idx];
       
    }
    return score;

}

    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        trieNode* root=new trieNode();
        for(auto &word:words){
            insert(root,word);
        }

        vector<int>result(n);
      

        for(int i=0;i<n;i++){
           result[i]= getScore(root,words[i]);
            
        }
        return result;
    }
};