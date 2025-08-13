class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(int i=0;i<num.size();i++){
            while(ans.length() >0 && ans.back()>num[i] && k>0){
                ans.pop_back();
                k--;
            }

            if(num[i]!='0' || ans.length()>0){
                ans.push_back(num[i]);
            }
        }

        //12345 k=3
        while(ans.length()>0 && k>0){
            ans.pop_back();
            k--;
        }
        if(ans==""){
            return "0";
        }

        return ans;

    }
};