// appracoh 1
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
    for (const string& word : words) {
        if (word.find(pref) == 0) { 
            count++;
        }
    }
    return count;
    }
};


// appraoch 2 using trie

class Solution {
public:
struct trieNode{
    trieNode* children[26];
    bool isendofWord;
    int count;
};


class Trie{
    public:
    trieNode* root;
    Trie(){
        root=getNode();
    }

    void insert(string &word){
        trieNode* crawler=root;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getNode();

            }
         
            crawler=crawler->children[idx];
            crawler->count++;
        }
        crawler->isendofWord=true;
    }
    int  search(string &prefix){
        trieNode* crawler=root;
        for(int i=0;i<prefix.length();i++){
            int idx=prefix[i]-'a';
            if(crawler->children[idx]==NULL){
                return 0;

            }
            crawler=crawler->children[idx];
        }
        return crawler->count;
    }
    private:
        trieNode* getNode(){
            trieNode* node=new trieNode();
            for(int i=0;i<26;i++){
                node->children[i]=NULL;
            }
            node->isendofWord=false;
            node->count=0;

            return node;
        }
};
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;

        for(string & word:words){
            trie.insert(word);
        }

        return trie.search(pref);
    }
};
