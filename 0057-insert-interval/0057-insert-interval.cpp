class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>result;
        int i=0;
        int n=intervals.size();

        while(i<n){
            if(intervals[i][1]<newInterval[0]){
                result.push_back(intervals[i]);
            }
            else if(intervals[i][0]>newInterval[1]){
                break;
            }
            else {
                newInterval[0]=min(intervals[i][0],newInterval[0]);
                newInterval[1]=max(intervals[i][1],newInterval[1]);

            }
            i++;
        }
        result.push_back(newInterval);

        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }

        return result;

    }
};