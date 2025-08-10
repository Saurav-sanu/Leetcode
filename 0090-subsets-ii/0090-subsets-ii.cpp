class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int index, vector<int> current, set<vector<int>>& st) {
        if (index == nums.size()) {
            st.insert(current);
            return;
        }

        // Choose the current element
        current.push_back(nums[index]);
        solve(nums, index + 1, current, st);

        // Skip the current element
        current.pop_back();
        solve(nums, index + 1, current, st);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int>current;
        sort(nums.begin(), nums.end());  // Sort the input to handle duplicates
        solve(nums, 0, current, st);          // Start recursion with an empty current subset
        result.assign(st.begin(), st.end());
        return result;
    }
};
