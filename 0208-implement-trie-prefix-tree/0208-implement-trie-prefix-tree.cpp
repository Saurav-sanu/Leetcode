class Trie {
public:
struct trieNode{
    bool isEndofword;
    trieNode* children[26];
};
trieNode* getNode(){
    trieNode* newNode=new trieNode();
    newNode->isEndofword=false;
    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
    return newNode;
}
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        trieNode* crawler=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int index=ch-'a';
            if(crawler->children[index]==NULL){
                crewler->children[index]=getNode();

            }
            crawler=crawler->children[index];
        }
        cwarler->isEndofword=true;

    }
    
    bool search(string word) {
        trieNode* crawler=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int index=ch-'a';
            if(crawler->children[index]==NULL){
                return false;
            }
            crawler=crawler->children[index];
        }
        if(crawler->isEndofword==true && crawler!=NULL){
            return true;
        } 
        return false;
    }
    
    bool startsWith(string prefix) {
         trieNode* crawler=root;
         int i=0;
        for(;i<prefix.length();i++){
            char ch=prefix[i];
            int index=ch-'a';
            if(crawler->children[index]==NULL){
                return false;
            }
            crawler=crawler->children[index];
        }
        if(i==prefix.length()){
            return true;
        }
        return false;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */