class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int l = INT_MAX;
        int r = INT_MIN;
        int hl = INT_MAX;
        int hh = INT_MIN;

        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                if(grid[row][col] == 1)
                {
                    l = min(l,col);
                    r = max(r,col);
                    hl = min(hl,row);
                    hh = max(hh,row);
                }
            }
        }

        if(l == INT_MAX && r == INT_MIN && hl == INT_MAX && hh == INT_MIN)
        {
            return 0;
        }

        return (hh - hl + 1)*(r - l + 1);
        
    }
};