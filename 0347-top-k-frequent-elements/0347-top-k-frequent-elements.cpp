class Solution {
public:
typedef pair<int,int>P;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<P,vector<P>,greater<P>>pq;
        unordered_map<int,int>mp;

        for(auto num:nums){
            mp[num]++;
        }

        for(auto &it:mp){
            int val=it.first;
            int freq=it.second;

            pq.push({freq,val});

            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int value=temp.second;
            ans.push_back(value);
        }
    return ans;


    }
};