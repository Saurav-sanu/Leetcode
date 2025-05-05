class Solution {
public:
int findDigitSum(int num){
    int sum=0;
    while(num){
        sum+=num%10;
        num=num/10;
    }
    return sum;
}
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int maxSize=0;
        int count=0;

        for(int num=1;num<=n;num++){
            int digitSum=findDigitSum(num);
            mp[digitSum]++;
            if(mp[digitSum]==maxSize){
                count++;
            }
            else if(mp[digitSum]>maxSize){
                maxSize=mp[digitSum];
                count=1;
            }
        }
        
        return count;

    }
};