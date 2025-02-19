class Solution {
public:
    int candy(vector<int>& rating) {
        int n=rating.size();
        vector<int>count(n,1);
        int sum=0;

        for(int i=1;i<n;i++){
            if(rating[i]>rating[i-1]){
                count[i]=max(count[i],count[i-1]+1);
            }
        }

        for(int i=n-2;i>=0;i--){
            if(rating[i]>rating[i+1]){
                count[i]=max(count[i],count[i+1]+1);
            }
        }

        for(int i=0;i<n;i++){
            sum+=count[i];
        }

        return sum;
        
    }
};