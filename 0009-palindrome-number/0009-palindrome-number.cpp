class Solution {
public:
int reverse(int x){
    long long ans=0;
    while(x){
        int digit=x%10;
        ans=ans*10+digit;
        x=x/10;
    }
    return ans;
}
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int c=reverse(x);
        if(x==c){
            return true;
        }
        return false;
    }
};