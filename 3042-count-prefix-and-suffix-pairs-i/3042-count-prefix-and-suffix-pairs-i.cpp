class Solution {
public:
struct trieNode{
    bool isendofWord;
    trieNode* children[26];
};

class Trie{
    public:
    trieNode* root;
    Trie(){
        root=getNode();
    }

    void insert(string word){
        trieNode* crawler=root;
        for(int i=-0;i<word.length();i++){
            int idx=word[i]-'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getNode();

            }
         
            crawler=crawler->children[idx];
        }
        crawler->isendofWord=true;
    }
    bool search(string prefix){
        trieNode* crawler=root;
        for(int i=0;i<prefix.length();i++){
            int idx=prefix[i]-'a';
            if(crawler->children[idx]==NULL){
                return false;

            }
            crawler=crawler->children[idx];
        }
        return true;
    }
    private:
    trieNode* getNode(){
        trieNode* node=new trieNode();
        node->isendofWord=false;
        for(int i=0;i<26;i++){
            node->children[i]=NULL;
        }

        return node;
    }
};
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int j=0;j<n;j++){
               Trie* prefixtree = new Trie();
            Trie* suffixtree = new Trie();


            prefixtree->insert(words[j]);

            string reversed=words[j];
            reverse(reversed.begin(),reversed.end());
            suffixtree->insert(reversed); 


            for(int i=0;i<j;i++){
                if(words[i].length()>words[j].length()){
                    continue;
                }

                string rev=words[j];
                reverse(rev.begin(),rev.end());

                if(prefixtree->search(words[i]) && suffixtree->search(rev)){
                    count++;
                }
            }

        }
        return count;
    }
};