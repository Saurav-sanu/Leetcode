class Solution {
public:
long long reverse(int x){
    long long ans=0;;
    while(x){
        int digit=x%10;
        ans=ans*10+digit;
        x/=10;
    }
    return ans;
}
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long reversenumber=reverse(x);
        if(x==reversenumber){
            return true;
        }
        return false;
    }
};