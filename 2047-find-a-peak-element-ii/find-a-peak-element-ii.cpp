class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int x = 0;
        int y = mat[0].size() - 1;

        while (x >= 0 && y >= 0 && x < mat.size() && y < mat[0].size()) {
            int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;

            // Check left neighbor
            if (y - 1 >= 0 && mat[x][y - 1] > mat[x][y]) {
                flag1 = 1;
                y--;
            }
            // Check right neighbor
            else if (y + 1 < mat[0].size() && mat[x][y + 1] > mat[x][y]) {
                flag2 = 1;
                y++;
            }
            // Check below neighbor
            else if (x + 1 < mat.size() && mat[x + 1][y] > mat[x][y]) {
                flag3 = 1;
                x++;
            }
            // Check above neighbor
            else if (x - 1 >= 0 && mat[x - 1][y] > mat[x][y]) {
                flag4 = 1;
                x--;
            }

            // If no flags are set, current position is a peak
            if (flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0) {
                return {x, y}; 
            }
        }

        return {-1, -1};  // Fallback, though there should always be a peak
    }
};
