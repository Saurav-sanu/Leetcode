class Solution {
public:
    int candy(vector<int>& rating) {
        int count=0;
        int n=rating.size();
        vector<int>lefttoright(n,1);
        vector<int>righttoleft(n,1);
        int sum=0;

        for(int i=1;i<n;i++){
            if(rating[i]>rating[i-1]){
                lefttoright[i]=max(lefttoright[i],lefttoright[i-1]+1);
            }
        }

        for(int i=n-2;i>=0;i--){
            if(rating[i]>rating[i+1]){
                righttoleft[i]=max(righttoleft[i],righttoleft[i+1]+1);
            }
        }

        for(int i=0;i<n;i++){
            sum+=max(lefttoright[i],righttoleft[i]);
        }

        return sum;

        
    }
};