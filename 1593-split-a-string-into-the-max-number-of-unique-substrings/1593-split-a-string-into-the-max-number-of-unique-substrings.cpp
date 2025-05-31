class Solution {
public:
unordered_set<string>st;
void solve(string s,int i,int currCount,int &maxCount){
    //base case
    if(i==s.length()){
        maxCount=max(maxCount,currCount);
        return;
    }

    for(int j=i;j<s.length();j++){
        string str=s.substr(i,j-i+1);
        if(st.find(str)==st.end()){
            st.insert(str);
            solve(s,j+1,currCount+1,maxCount);
            st.erase(str);
        }
    }
}
    int maxUniqueSplit(string s) {
        int currCount=0;
        int maxCount=0;
        solve(s,0,currCount,maxCount);
        return maxCount;
    }
};