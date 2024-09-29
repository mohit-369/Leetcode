class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int start = 0;

        int end = matrix.size() * matrix[0].size() - 1;

        int cols = matrix[0].size();


        while(end - start > 1)
        {
            int mid = (end - start)/2 + start;

            int x = mid / cols;

            int y = mid % cols;

            if(matrix[x][y] == target) return 1;

            else if(matrix[x][y] > target) end = mid - 1;

            else
            {
                start = mid + 1;
            }
        }

        if(matrix[start/cols][start%cols] == target) return 1;

        if(matrix[end/cols][end%cols] == target) return 1;

        return 0;
        
    }
};