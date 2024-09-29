class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int i = 0;

        int j = matrix[0].size() - 1;

        int rows = matrix.size();

        int cols = matrix[0].size();

        while( i >= 0 && j >= 0 && i < rows && j < cols)
        {
            if( matrix[i][j] == target) return 1;

            else if(matrix[i][j] < target) 
            {
                i++;
            }

            else
            {
                j--;
            }
        }

        return 0;
        
    }
};