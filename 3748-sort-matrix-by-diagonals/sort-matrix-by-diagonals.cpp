class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        unordered_map<int,priority_queue<int,vector<int>, greater<int>>> min_heap;
        unordered_map<int,priority_queue<int,vector<int>>> max_heap;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(i < j)
                {
                    min_heap[i-j].push(grid[i][j]);
                }

                else
                {
                    max_heap[i-j].push(grid[i][j]);
                }
            }
        }

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(i < j)
                {
                    grid[i][j] = min_heap[i-j].top();
                    min_heap[i-j].pop();
                }
                else
                {
                    grid[i][j] = max_heap[i-j].top();
                    max_heap[i-j].pop();
                }
            }
        }

        return grid;
        
    }
};