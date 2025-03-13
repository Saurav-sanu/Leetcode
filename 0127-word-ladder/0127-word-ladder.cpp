class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            string word=node.first;
            int step=node.second;
            int size=node.first.length();



            if(word==endWord){
                return step;
            }



            for(int i=0;i<size;i++){
                char ch=word[i];
                for(ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word=node.first;
            }
        }

        return 0;


    }
};