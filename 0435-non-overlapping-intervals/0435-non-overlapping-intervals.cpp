class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<int>L=intervals[0];

        int i=0;
        int count=0;
        while(i<n){
            int curr_start=intervals[i][0];
            int curr_end=intervals[i][1];

            int last_end= L[1];
            int last_start=L[0];
            if(last_end<=curr_start){
                i++;
                L=intervals[i];
            }
            else if(last_end>last_end){
                count++;
                i++;
            }
            else{
                L=intervals[i];
                i++;
                count++;
            }
        }
        return count;
        
    }
};