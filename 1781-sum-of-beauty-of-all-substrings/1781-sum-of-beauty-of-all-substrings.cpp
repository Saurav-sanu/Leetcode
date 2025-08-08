class Solution {
public:
int mini(vector<int>&str){
    int minElement=INT_MAX;
    for(int i=0;i<str.size();i++){
        if(str[i]!=0){
            minElement=min(minElement,str[i]);
        }
    }
    return minElement;
}
int maxi(vector<int>&str){
    return *max_element(str.begin(),str.end());

}
    int beautySum(string s) {
        int sum=0;
        int n=s.length();

        for(int i=0;i<n;i++){
            vector<int>str(256,0);
            for(int j=i;j<n;j++){
                str[s[j]-'a']++;
                int diff=maxi(str)-mini(str);
                sum+=diff;
            }
            
        }
        return sum;
    }
};