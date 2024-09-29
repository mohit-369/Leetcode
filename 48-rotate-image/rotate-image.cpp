class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        for(int col = 0; col < matrix[0].size(); col++)
        {
            int start = 0;
            int end = matrix.size()-1;

            while(start < end)
            {
                swap(matrix[start][col],matrix[end][col]);
                start++;
                end--;
            }
        }

        for(int row = 0; row < matrix.size(); row++)
        {
            for(int col = row; col < matrix.size(); col++)
            {
                swap(matrix[row][col],matrix[col][row]);
            }
        }

        return ;
        
    }
};