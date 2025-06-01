class Solution {
public:
int solve(vector<int>&freq){
    int ans=0;
    //hr dabbe mai a se z insert 
    for(int i=0;i<26;i++){
        //ek ans aa gya
        if(freq[i]!=0){
            ans++;
            freq[i]--;
            //baki recursion
        int recursionkaans= solve(freq);
        ans+=recursionkaans;
        freq[i]++;
        }
    }
    return ans;
}
    int numTilePossibilities(string tiles) {
        vector<int>freq(26,0);
        for(auto ch:tiles){
            freq[ch-'A']++;
        }
        int ans=solve(freq);
        return ans;

    }
};