class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int j = 1;
        int n = intervals.size();
        vector<vector<int>> result;

        while (j < n) {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            int next_start = intervals[j][0];
            int next_end = intervals[j][1];

            // Overlapping condition
            if (curr_end >= next_start) {
                // Merge intervals
                curr_end = max(curr_end, next_end);
                intervals[i] = {curr_start, curr_end};
            } else {
                // Push merged interval and move to next
                result.push_back({curr_start, curr_end});
                i = j;
            }
            j++;
        }
        
        // Push the last interval
        result.push_back(intervals[i]);

        return result;
    }
};
