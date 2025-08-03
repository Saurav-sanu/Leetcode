class Solution {
public:
    int reverse(int x) {
       long long ans=0;
        while(x){
            int digit=x%10;
            ans=ans*10+digit;
            x=x/10;
        }
        return ans;
    }
    
};