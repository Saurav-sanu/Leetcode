class Solution {
public:
    bool isSafe(int newX, int newY, map<pair<int, int>, bool>& vis, vector<vector<int>>& ans, vector<vector<int>>& image, int oldColor) {
        if (newX >= 0 && newY >= 0 && newX < image.size() && newY < image[0].size() && ans[newX][newY] == oldColor && !vis[{newX, newY}]) {
            return true;
        }
        return false;
    }

    void dfs(int oldColor, int newColor, map<pair<int, int>, bool>& vis, vector<vector<int>>& ans, vector<vector<int>>& image, int sr, int sc) {
        vis[{sr, sc}] = true;
        ans[sr][sc] = newColor;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newX = dx[i] + sr;
            int newY = dy[i] + sc;
            if (isSafe(newX, newY, vis, ans, image, oldColor)) {
                dfs(oldColor, newColor, vis, ans, image, newX, newY);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor == color) {
            return image; // No need to fill if the color is the same
        }
        vector<vector<int>> ans = image; // Initialize ans with the original image
        map<pair<int, int>, bool> vis;
        dfs(oldColor, color, vis, ans, image, sr, sc);
        return ans;
    }
};