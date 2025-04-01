class Solution {
public:
    int rob(vector<int>& nums) {
       

        //using space optimisation
        int n=nums.size();
        vector<int>t(n+1,0);

        int prevprev=0;
        int prev=nums[0];

        for(int i=2;i<=n;i++){
            int skip=prev;
            int take=nums[i-1]+prevprev;

            int temp=max(skip,take);

            prevprev=prev;
            prev=temp;
        }

        return prev;


    }
};


//uisng space optimisatoin
class Solution {
public:
    int rob(vector<int>& nums) {
       

        //using space optimisation
        int n=nums.size();
        vector<int>t(n+1,0);

        int prevprev=0;
        int prev=nums[0];

        for(int i=2;i<=n;i++){
            int skip=prev;
            int take=nums[i-1]+prevprev;

            int temp=max(skip,take);

            prevprev=prev;
            prev=temp;
        }

        return prev;


    }
};
