class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int left = 0, top = 0;

        int bottom = matrix.size() -1;

        int right = matrix[0].size() -1;

        vector<int> ans;

        while(top<=bottom && left <= right)
        {
            int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
            for(int i = left ; i <= right; i++)
            {
                int ele = matrix[top][i];

                ans.push_back(ele);

                f1 = 1;
            }

            top++;

            for(int i = top ; i <= bottom; i++)
            {
                int ele = matrix[i][right];
                ans.push_back(ele);

                f2 = 1;

            }

            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                    f3 = 1;
                }
                bottom--;
            }


            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]); 
                    f4 = 1;
                }
                left++;
            }

            if(f1 == 0 && f2 == 0 && f3 == 0 && f4 ==0) break;
        }

        return ans;
        
    }

    
};