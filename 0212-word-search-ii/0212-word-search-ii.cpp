class Solution {
public:
vector<vector<int>>direction{{1,0},{-1,0},{0,1},{0,-1}};
vector<string>result;
struct trieNode{
    bool endofWord;
    string word;
    trieNode* children[26];
};

trieNode* getNode(){
    trieNode* newNode=new trieNode();
    newNode->endofWord=false;
    newNode->word="";
    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
    return newNode;
}

void insert(trieNode* root,string& word){
    trieNode* crawler=root;
    for(int i=0;i<word.length();i++){
        char ch=word[i];
        if(crawler->children[ch-'a']==NULL){
            crawler->children[ch-'a']=getNode();
        }
        crawler=crawler->children[ch-'a'];
    }
    crawler->endofWord=true;
    crawler->word=word;

    

}

void findcharWord(vector<vector<char>>& board,int i,int j,trieNode* &root){
    //base case
    int m=board.size();
    int n=board[0].size();


    if(i<0 ||i>=m || j<0 || j>=n){
        return ;
    }

    if(board[i][j]=='$' || root->children[board[i][j]-'a']==NULL){
        return;
    }
      char ch = board[i][j];

     trieNode* nextNode = root->children[ch - 'a']; // \U0001f504 Changed: use temporary pointer

        if (nextNode->endofWord == true) {
            result.push_back(nextNode->word);
            nextNode->endofWord = false; // prevent duplicates
        }

        board[i][j] = '$'; // mark visited

        for (auto& dir : direction) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            findcharWord(board, new_i, new_j, nextNode); // \U0001f504 Changed: pass nextNode instead of root
        }

        board[i][j] = ch; 

}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m=board.size();
        int n=board[0].size();

        //create root;
        trieNode* root=getNode();


        //insert node
        for(string &word:words){
            insert(root,word);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL){
                    findcharWord(board,i,j,root);
                }
            }
        }
        return result;


    }
};