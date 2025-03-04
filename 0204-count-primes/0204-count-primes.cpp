class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        if(n==2){
            return 0;
        }
        vector<bool>isPrime(n+1,true);

        isPrime[0]=false;
        isPrime[1]=false;

        for(int i=2;i<=n;i++){
            if(isPrime[i]==true){
                count++;
                for(int j=2;i*j<=n;j++){
                    isPrime[i*j]=false;
                }
            }
        }
        return count;
    }
};