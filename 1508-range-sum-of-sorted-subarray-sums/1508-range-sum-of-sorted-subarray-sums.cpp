class Solution {
public:
typedef pair<int,int>P;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P,vector<P>,greater<P>>pq;
        int m=1000000007;
       
        long long sum=0;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        vector<int>ans;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int sum=top.first;
            int index=top.second;
            ans.push_back(sum);

            if(index+1<n){
                pq.push({nums[index+1]+sum,index+1});
            }
            
        }
        for(int i=left-1;i<right;i++){
            sum+=ans[i];
        }
        return sum%m;
    }
};