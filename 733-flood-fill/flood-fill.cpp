class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &ans, int delRow[], int delCol[], int newColor, int iniColor, vector<vector<int>> &image) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, delRow, delCol, newColor, iniColor, image);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];

        // If the color is already the new color, no need to do anything
        if (iniColor == color) return image;

        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, delRow, delCol, color, iniColor, image);

        return ans;
    }
};
