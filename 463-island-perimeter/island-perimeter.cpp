class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int ans=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int count=0;

                if((i-1)>=0 && grid[i-1][j] && grid[i][j])
                {
                    count++;
                }

                if((i+1)<grid.size() && grid[i+1][j] && grid[i][j])
                {
                    count++;
                }

                if((j+1)<grid[0].size() && grid[i][j+1] && grid[i][j])
                {
                    count++;
                }

                if((j-1)>=0 && grid[i][j-1] && grid[i][j])
                {
                    count++;
                }

                if(grid[i][j]) ans+=4-count;
            }
        }

        return ans;
        
    }
};